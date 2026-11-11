#include <bits/stdc++.h>
using namespace std;

long long read()
{
    long long x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

long long c, t, n, d, a[5010], sa[5010], ans, g[5010][5010], dis[5010][5010], cnt[5010][5010];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    c = read(), t = read();
    while (t--)
    {
        n = read(), d = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            a[i] -= a[1];
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            g[i][i] = 0;
            for (int j = i + 1; j <= n; j++)
            {
                g[i][j] = g[j][i] = a[j] - a[i];
                if (g[i][j] <= d) dis[i][j] = dis[j][i] = cnt[i][j] = cnt[j][i] = 1;
            }
        }
        memset(dis, 0x3f, sizeof dis);
        for (int i = 1; i <= n; i++) dis[i][i] = 0;
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (dis[i][j] > dis[i][k] + dis[k][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        cnt[i][j] = 1;
                    }
                    else if (dis[i][j] == dis[i][k] + dis[k][j])
                    {
                        cnt[i][j] ++;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans += (cnt[i][j] == 2);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
