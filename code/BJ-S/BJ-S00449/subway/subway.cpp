#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int nr = 5e5 + 10;
const int mr = 510;
const ll inf = 2e18;
int n, m, D, q, a[nr]; ll dis[mr][mr];
vector<pair<int, int> > g[nr];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int CASE; cin >> CASE;
    cin >> m >> n >> D >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int k; cin >> k;
        while (k--)
        {
            int x, v; cin >> x >> v;
            g[x].push_back(make_pair(i, v));
        }
    }
    for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) dis[i][j] = inf;
    for (int i = 1; i <= m; i++) dis[i][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int a = 0; a < g[i].size(); a++) for (int b = a + 1; b < g[i].size(); b++)
        {
            int x = g[i][a].first, vx = g[i][a].second;
            int y = g[i][b].first, vy = g[i][b].second;
            dis[x][y] = dis[y][x] = min(dis[x][y], (ll)(vx + vy));
        }
    }
    for (int k = 1; k <= m; k++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        int u, v; cin >> u >> v;
        ll res = inf;
        for (int i = 0; i < g[u].size(); i++) for (int j = 0; j < g[v].size(); j++)
        {
            int x = g[u][i].first, vx = g[u][i].second;
            int y = g[v][j].first, vy = g[v][j].second;
            res = min(res, dis[x][y] + vx + vy);
        }
        cout << a[u] + res + a[v] << '\n';
    }
    return 0;
}
