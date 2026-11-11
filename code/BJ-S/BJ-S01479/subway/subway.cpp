#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define int long long
using namespace std;
const int M = 2000, INF = 0x3f3f3f3f3f3f3f3f;
int w[M + 5], c, n, m, d, q;
struct Edge {
    int v, w;
};
vector<Edge> g[500505];
int dis[2505][2505], ddis[500505];
void dij(int s) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    ddis[s] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        int u = cur.second;
        pq.pop();
        for (auto nxt : g[u]) {
            int v = nxt.v, w = nxt.w;
            if (ddis[v] > ddis[u] + w) {
                ddis[v] = ddis[u] + w;
                pq.push({-ddis[v], v});
            }
        }
    }
}
signed main() {
    #ifndef SELFTEST
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    #endif // SELFTEST
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k, v, w;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> v >> w;
            g[m + i].push_back({v, w});
            g[v].push_back({m + i, w});
            dis[m + i][v] = dis[v][m + i] = w;
        }
    }
    bool mark = true;
    if (mark) {
        for (int k = 1; k <= m + n; k++) {
            for (int i = 1; i <= m + n; i++) {
                for (int j = 1; j <= m + n; j++) {
                    if (i == j) dis[i][j] = 0;
                    if (dis[i][k] == INF || dis[k][j] == INF) continue;
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (mark) {
            if (x > y) swap(x, y);
            cout << w[x] + w[y] + dis[x][y] << endl;
        } else {
            memset(ddis, 0x3f, sizeof ddis);
            dij(x);
            cout << w[x] + w[y] + ddis[y] << endl;
        }
    }
}
// 32pts
