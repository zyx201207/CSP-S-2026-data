#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],la[300005],f[500005],ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        la[a[i]] = i;
        f[i] = 1;
    }
    for (int i = 1;i <= n;i++)
    {
        int x = la[a[i]];
        ans[a[i]] += f[i];
        f[x + 1] += f[i];
    }
    for (int i = 1;i <= m;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
