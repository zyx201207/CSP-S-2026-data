#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r",stdin);
    freopen("travel.out", "w",stdout);
    int r, rc, x, xc;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    cin >> r >> rc >> x >> xc;
    for(int i = 1;i < r;i++)
    {
        if (r == x)
        {
            sum1 = 1;
        }
        else
        {
            sum1 = 0;
        }
        if(rc == xc)
        {
            sum2 = 1;
        }
        else
        {
            sum2 = 0;
        }
        if(rc - xc or xc - rc)
        {
            sum3 = 1;
            sum4 = 1;
        }
        else
        {
            sum3 = 0;
            sum4 = 0;
        }
        cout << sum1 << sum2 << sum3 << sum4;
    }
    return 0;
}
