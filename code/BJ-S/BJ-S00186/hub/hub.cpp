#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
ll c, t, n, k, u, v, dist[3005][3005];
vector <ll> graph[N];
void Bfs(ll x) {
    queue <ll> q;
    bool vis[10005] = {};
    q.push(x);
    dist[x][x] = 0;
    vis[x] = 1;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (const auto &v : graph[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[x][v] = dist[x][u] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (ll i = 1; i <= n - 1; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (ll i = 1; i <= n; i++) Bfs(i);
        ll res = 0, ans = 0;
        for (ll i = 1; i <= n - 1; i++) {
            for (ll j = i + 1; j <= n; j++) {
                ans = 0;
                for (ll k = 1; k <= n; k++) {
                    if (k != i && k != j) {
                        ll dis = min(dist[i][k], dist[j][k]);
                        ans = max(ans, dis);
                    }
                }
                res = max(res, ans);
            }
        }
        cout << res << "\n";
    }
    return 0;
}
