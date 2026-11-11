#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {

        cin >> a[i];
    }
    if (m == 1)
    {
        for (int i = 1;i <= n;i++)
        {
            if (a[i] > maxn)
            {
                maxn = a[i];
            }
        }
    }
    if (m == n)
    {
        maxn = a[1];
        for (int i = 2;i <= n;i++)
        {
            maxn = (maxn & a[i]);
        }
    }
    cout << maxn;
    return 0;
}
