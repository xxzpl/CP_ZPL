/* A single root of an equation f(x)=0 in [a,b] interval
 * Method: call Bisectional method */

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double root_bs(double(*) (double), double, double, double, int& flag );
double fzero(double);

int main(){
    double a, b, root, eps;
    int flag;
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(6);

    a = 1.0;    // left  endpoint
    b = 4.0;    // right endpoint
    eps = 1.0e-6;     // desired uncertainity of the root
    
    root = root_bs(fzero, a, b, eps, flag);
    
    if (flag==0) cout << " no root for Bisectional method" << endl;
    else{
        cout << " iterations" << "    root" << endl;
        cout << setw(7) << flag << setw(14) << root <<endl;
    }
    return 0;
}


/* Function f(x) for the Eq. f(x)=0 */

double fzero(double x){
    double y;
    y = exp(x)*log(x) - cos(x*x);
    // y = log(x*x+2.0)*cos(x)+sin(x)
    // y = x*x-6.0*x+9.0
    return 0;
}

double root_bs(double(*f) (double), double a, double b, double eps, int& flag){
/*==================================================================
 *Program to find a single root of an equation f(x)=0
 *using the bisectional method
 *Author: Peiliang Zhao                                          
 -------------------------------------------------------------------
 input ---
 f    - function which evaluates f(x) for any x in the [a,b]
 a    -
 b    -
 eps  - desired uncertainity of the root

 output ---
 x0   - root of equation f(x)=0 
 flag - indicator of success
        0 - no solutions for the Bisectional method
        1 - a single root found after i iterations
 
 Limitations: a function f(x) must chage sign between a and b
 max number of allowed iterations is 1000  (accuracy (b-a)/2**1000)
 ================================================================== */

    double xl, x0, xr;
    int i, iter=1000;

    // check the bisection condition
    if (f(a)*f(b) > 0.0 ){
        flag = 0;
        return 0.0;
    }
    
    // finding a single root
    i = 0;
    xl = a;
    xr = b;

    while (fabs(xr-xl) >= eps){
        i = i+1;
        x0 = (xr+xl)/2.0;
        if ( f(xl)*f(x0) <=0.0 ){
            xr =x0;}
        else{xl =x0;}
        
        if (i>=iter) break;
    }
    flag = i;
    return x0;
}
