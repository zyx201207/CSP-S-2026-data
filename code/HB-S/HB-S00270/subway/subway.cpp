#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
ll c, n, m, d, q, w[500005], g2[505][505];
vector<pair<ll, ll>> g1[500005];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            ll a, t;
            cin >> a >> t;
            g1[a].push_back({i, t});
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g2[i][j] = (i == j ? 0 : INF);
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < g1[i].size(); j++)
            for (int k = j + 1; k < g1[i].size(); k++) {
                ll x = g1[i][j].first, y = g1[i][k].first;
                g2[x][y] = g2[y][x] = min(g2[x][y], g1[i][j].second + g1[i][k].second);
            }

    ll dist[505];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> qu;
    while (q--) {
        ll x, y, ans = INF;
        cin >> x >> y;
        for (int i = 1; i <= n; i++)
            dist[i] = INF;
        for (int i = 0; i < g1[x].size(); i++)
            qu.push({g1[x][i].second, g1[x][i].first});
        while (!qu.empty()) {
            ll t = qu.top().first, u = qu.top().second;
            qu.pop();
            if (t >= dist[u])
                continue;
            dist[u] = t;
            for (int i = 1; i <= n; i++)
                qu.push({t + g2[u][i], i});
        }
        for (int i = 0; i < g1[y].size(); i++)
            ans = min(ans, dist[g1[y][i].first] + g1[y][i].second);
        ans += w[x] + w[y];
        cout << ans << "\n";
    }
    return 0;
}
