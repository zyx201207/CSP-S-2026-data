#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 505, MAXM = 5e5 + 5;
const ll inf = 1e18;
int c, n, m, d, q;
ll w[MAXM];
ll dis[MAXN][MAXN];
vector<int> line[MAXN], sta[MAXM];
map<int, ll> tim[MAXN];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i)
        cin >> w[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = inf;
    for (int i = 1, cnt; i <= n; ++i)
    {
        cin >> cnt;
        for (int j = 1, x, t; j <= cnt; ++j)
        {
            cin >> x >> t;
            line[i].push_back(x);
            sta[x].push_back(i);
            tim[i][x] = t;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            for (auto x : line[i])
                if (tim[j].count(x))
                    dis[i][j] = dis[j][i] = min(dis[i][j], tim[i][x] + tim[j][x]);
        }
    }
    for (int i = 1; i <= n; ++i)
        dis[i][i] = 0;
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int x, y; q; q--)
    {
        cin >> x >> y;
        ll ans = inf;
        for (auto a : sta[x])
        {
            for (auto b : sta[y])
            {
                ans = min(ans, dis[a][b] + tim[a][x] + tim[b][y]);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }

    return 0;
}
