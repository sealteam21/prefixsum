#include <iostream>
#include <cmath>
#include <omp.h>

using namespace std;

int main()
{
    
     const int size = 256;
    const double step = (2.0 * M_PI) / static_cast<double>(size); 
    double* sinTable = new double[size];
    double sum = 0.0;

    
    #pragma omp parallel for reduction(+:sum)    
    for (int n = 0; n < size; n++)
    {
        sinTable[n] = std::sin( static_cast<double>(n) * step);      
        sinTable[n] = sinTable[n] * 2.0;  
        sum += sinTable[n];  
    }
    
    //print
    cout << "Sum: " << sum << endl;
    delete[] sinTable;
    return 0;
}
