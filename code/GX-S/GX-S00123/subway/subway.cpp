#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
using ll = long long;

const int M = 2e4 + 1, N = 501;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct state {
    ll dis;
    int id, u;
    bool operator< (const state nxt) const {
        return dis > nxt.dis;
    }
};
int c, n, m, d, q, w[M], a[M], t[N][M];
ll dis[M][N];
vector<pair<int, int>> g[M], query;
void dij(int s) {
    priority_queue<state> pq;
    memset(dis, 0x3f, sizeof dis);
    dis[s][0] = 0;
    pq.push({0, 0, s});
    while (!pq.empty()) {
        auto [l, id, u] = pq.top();
        pq.pop();
        if (l != dis[u][id]) {
            continue;
        }
        for (auto [v, id_] : g[u]) {
            if (id == id_ && dis[v][id] > dis[u][id] + t[id][v]) {
                dis[v][id] = dis[u][id] + t[id][v];
                pq.push({dis[v][id], id, v});
            } else if (id != id_ && dis[v][id_] > dis[u][id] + t[id_][u] + t[id_][v]) {
                dis[v][id_] = dis[u][id] + t[id_][u] + t[id_][v];
                pq.push({dis[v][id_], id_, v});
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
            cin >> a[j] >> t[i][a[j]];
            if (j > 1) {
                for (int z = 1; z < j; z++) {
                    g[a[j]].push_back({a[z], i});
                    g[a[z]].push_back({a[j], i});
                }
            }
        }
    }
    while (q--) {
        int s, t;
        cin >> s >> t;
        dij(s);
        ll tmp = INF;
        for (int i = 1; i <= n; i++) {
            tmp = min(tmp, dis[t][i]);
        }
        cout << w[s] + w[t] + tmp << '\n';
    }
    return 0;
}
