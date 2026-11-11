#include <iostream>
#include <string.h>
using namespace std;

int cx_r;
string xh_r;
int cx_x;
string xh_x;
int pd;

int main()
{
    cin >> cx_r >> xh_r >> cx_x >> xh_x;
    if(cx_r == cx_x)
        cout << 1;
    else
        cout << 0;



    if(xh_r[0] == xh_x[0] && xh_r[1] == xh_x[1] && xh_r != xh_x)
        cout << 1;
    else
        cout << 0;



    if(xh_r[2] != 'D' && xh_r != xh_x)
        cout << 1;
    else if(xh_r[2] !='F' && xh_r != xh_x)
        cout << 1;
    else if(xh_x[2]  != 'D' && xh_r != xh_x)
        cout << 1;
    else if(xh_x[2] !='F' && xh_r != xh_x)
        cout << 1;
    else cout << 0;



    if(xh_r[2]  == 'A' && xh_x[2] == 'B')
        cout << 1;
    else if(xh_r[2]  == 'B' && xh_x[2] == 'C')
        cout << 1;
    else if(xh_r[2]  == 'D' && xh_x[2] == 'F')
        cout << 1;
    else
        cout << 0;
    return 0;
}
