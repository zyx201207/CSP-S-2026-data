#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],u,v;
long long sum;
void solve()
{
    int sx,sy,ex,ey;
    bool flag1 = 0,flag2 = 0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= k[i];j++)
        {
            if (a[i][j] == u)
            {
                sx = i;
                sy = j;
                flag1 = 1;
            }
        }
        if (flag1)
        {
            break;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= k[i];j++)
        {
            if (a[i][j] == v)
            {
                ex = i;
                ey = j;
                flag2 = 1;
            }
        }
        if (flag2)
        {
            break;
        }
    }
    if (sx != ex)
    {
        for (int j = 1;j <= k[sx];j++)
        {
            sum += t[sx][j];
            if (a[sx][j] == ex)
            {
                break;
            }
        }
        for (int j = 1;j <= k[ex];j++)
        {
            sum += t[ex][j];
            if (a[ex][j] == v)
            {
                break;
            }
        }
    }
    else
    {
        for (int j = 1;j <= k[ex];j++)
        {
            sum += t[ex][j];
            if (a[ex][j] == v)
            {
                break;
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
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
        }
    }
    while (q--)
    {
        cin >> u >> v;
        sum = 0;
        sum += w[u] + w[v];
        solve();
        cout << sum << endl;
    }
    return 0;
}
