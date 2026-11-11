#include <bits/stdc++.h>
#define pii pair<long long, int>
using namespace std;
const int N = 505, M = 5e5 + 5;
typedef long long ll;
const ll inf = 1e18;
int c, n, m, d, q;
ll w[M];
vector<int> pass[M];
ll t[N][M];
ll dist[N][N], adj[N][N];
void dijesktra(int s) {
    priority_queue<pii> q;
    dist[s][s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().second;
        long long val = q.top().first;
        q.pop();
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] == inf)  continue;
            if (dist[s][v] > dist[s][u] + adj[u][v]) {
                dist[s][v] = dist[s][u] + adj[u][v];
                q.push({dist[s][v], v});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a;
            cin >> a >> t[i][a];
            pass[a].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = adj[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int u : pass[i]) {
            for (int v : pass[i]) {
                if (u == v)  continue;
                adj[u][v] = min(adj[u][v], t[u][i] + t[v][i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dijesktra(i);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = inf;
        for (int u : pass[x]) {
            for (int v : pass[y]) {
                ans = min(ans, dist[u][v] + t[u][x] + t[v][y]);
            }
        }
        ans += (w[x] + w[y]);
        cout << ans << '\n';
    }
    cout << endl;
    return 0;
}