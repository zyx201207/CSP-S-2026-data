#include <bits/stdc++.h>
using namespace std;
long long f[200005],n,m,a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = min(i,m);j > 0;j--)
        {
            f[j] = max(a[j],(j == 1) ? a[i] : (a[j] & a[j - 1]));
        }
    }
    cout << f[n];
    return 0;
}
