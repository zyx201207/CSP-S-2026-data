#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c, n, m, d, q, dis[500005], f[505][505];
vector<pair<ll, ll>> g[500005];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        ll w;
        cin >> w;
        dis[i] = w;
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            ll x, w;
            cin >> x >> w;
            g[x].push_back({i, w});
        }
    }
    for (int i = 1; i <= m; i++)
        for (auto [u, w] : g[i])
            for (auto [v, w2] : g[i])
            {
                if (u == v) continue;
                f[u][v] = f[v][u] = min(f[u][v], w + w2);
            }
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--)
    {
        ll x, y, ans = 1e9;
        cin >> x >> y;
        for (auto [u, w] : g[x])
            for (auto [v, w2] : g[y]) ans = min(ans, f[u][v] + dis[x] + dis[y] + w + w2);
        cout << ans << '\n';
    }
}