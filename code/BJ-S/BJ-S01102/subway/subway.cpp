#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, n, m, d, q, w[500005], k, a, t, x, y;
vector<pair<ll, ll> > st[500005];
ll dis[505][505];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dis, 0x3f, sizeof(dis));
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) scanf("%lld", &w[i]);
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
        scanf("%lld", &k);
        for (int j = 1; j <= k; j++)
        {
            scanf("%lld%lld", &a, &t);
            for (int l = 0; l < st[a].size(); l++)
            {
                ll to = st[a][l].first, len = st[a][l].second + t;
                dis[i][to] = min(dis[i][to], len);
                dis[to][i] = min(dis[to][i], len);
            }
            st[a].emplace_back(i, t);
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        scanf("%lld%lld", &x, &y);
        ll ans = 9e18;
        for (int i = 0; i < st[x].size(); i++)
            for (int j = 0; j < st[y].size(); j++)
            {
                ll to1 = st[x][i].first, to2 = st[y][j].first;
                ll len = w[x] + st[x][i].second + st[y][j].second + w[y];
                ans = min(ans, len + dis[to1][to2]);
            }
        printf("%lld\n", ans);
    }
    return 0;
}
