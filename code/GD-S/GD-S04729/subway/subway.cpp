#include <bits/stdc++.h>
using namespace std;
long long dis[502][502], n, m, d, w[500005], k[502], q, c, inf = 1e16;
vector<pair<long long, long long>> st[500005];
vector<pair<long long, long long>> tts[502];
inline long long fr()
{
    long long x = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
        x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    // cin >> c >> n >> m >> d >> q;
    c = fr();
    n = fr();
    m = fr();
    d = fr();
    q = fr();
    for (long long i = 1; i <= m; i++)
    {
        // cin >> w[i];
        w[i] = fr();
    }
    for (long long i = 1; i <= n; i++)
    {
        // cin >> k[i];
        k[i] = fr();
        for (long long j = 1; j <= k[i]; j++)
        {
            long long a, t;
            // cin >> a >> t;
            a = fr();
            t = fr();
            st[a].push_back({i, t});
            tts[i].push_back({a, t});
        }
        for (long long j = 1; j <= n; j++)
        {
            dis[i][j] = inf;
        }
        dis[i][i] = 0;
    }
    for (long long i = 1; i <= n; i++)
    {
        for (auto S : tts[i])
        {
            long long t0 = S.second;
            for (auto stat : st[S.first])
            {
                if (stat.first == i)
                    continue;
                dis[i][stat.first] = min(dis[i][stat.first], t0 + stat.second);
            }
        }
    }
    // floyd
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            for (long long k = 1; k <= n; k++)
            {
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
    for (long long i = 1; i <= q; i++)
    {
        long long x, y;
        // cin >> x >> y;
        x = fr();
        y = fr();
        long long a0 = w[x] + w[y], ans = inf;
        for (auto S : st[x])
        {
            for (auto T : st[y])
            {
                ans = min(ans, dis[S.first][T.first] + S.second + T.second);
            }
        }
        cout << a0 + ans << '\n';
    }
    return 0;
}
