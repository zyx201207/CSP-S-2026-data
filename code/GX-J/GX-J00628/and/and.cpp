#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    freopen("and.in","r","std");
    freopen("and.out","w","std");
    int n,m;
    int a[100000];
    cin >> n >> m;
    for (int i = 1; i<= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int maxx= -1;
        if (a[i] > maxx)
        {
            maxx = a[i];
        }
    }
    cout << a[3];
;    return 0;
}
