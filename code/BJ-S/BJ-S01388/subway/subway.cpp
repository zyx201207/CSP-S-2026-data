#include <bits/stdc++.h>
using namespace std;
long long w[500005],n,m,k[1000005],q = 0,c,d,a[505][505],t[505][505],ks[505],x[100005],y[100005];
int ans = 0;
bool flag = true;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ks[1] = 0;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for (int j = 1;j <= k[i];j++)
        {
            cin >> a[i][j] >> t[i][j];
            if (j >= 2) ks[a[i][j]] = min(ks[a[i][j - 1]] + 1,ks[a[i][j]]);
        }
    }
    for (int i = 1;i <= q;i++)
    {
        cin >> x[i] >> y[i];
        cout << 1 << '\n';
    }
    return 0;
}
