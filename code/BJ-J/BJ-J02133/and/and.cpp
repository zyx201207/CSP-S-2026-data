#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("amd.out","w",stdout);
    int n, m, sum = 0, maxn;
    cin >> n  >> m;
    for(int i = 1;i <=n;i++)
    {
        cin >> a[i];
        sum = a[i] | sum;
        maxn = max(maxn,a[i]);
    }
    if(m == 1)
    {
        cout << maxn;
    }
    else
    {
        cout << sum;
    }
}
