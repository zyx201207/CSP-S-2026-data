#include <bits/stdc++.h>

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

#define fst first
#define snd second

using namespace std;
using ll = long long;
using ld = long double;
const int N = 505, M = 500005;
struct Edge { ll to, w; };
struct Node { ll u, sum, s; bool operator < (const Node &t) const { return sum > t.sum; } };
ll Testid, n, m, x, q, t;
ll w[M], dis[N + M], d[N][N];
bool vis[N + M];
vector <Edge> G[N + M];
void dijkstra(int s, int id) {
    for (int i = 1; i <= id; i++) d[id][i] = LMX;
    d[id][id] = 0;
    for (int i = 1; i <= n + m; i++) dis[i] = LMX, vis[i] = 0;
    priority_queue <Node> pq;
    pq.push({s, 0, 0}), dis[s] = 0;
    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        if (vis[cur.u] or cur.s == 2) continue;
        vis[cur.u] = 1;
        for (auto v : G[cur.u]) { if (cur.sum + v.w < dis[v.to]) dis[v.to] = cur.sum + v.w, pq.push({v.to, dis[v.to], cur.s + 1}); }
    }
    for (int j = 1; j < id; j++) {
        if (dis[j + m] == LMX) continue;
        for (int k = 1; k <= j; k++) d[id][k] = min(d[id][k], d[j][k] + dis[j + m]);
    }
}
ll DIS(int x, int y) { if (x < y) swap(x, y); return d[x][y]; }
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> Testid >> n >> m >> x >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        while (k--) {
            int u, w; cin >> u >> w; t = w;
            G[u].push_back({i + m, w});
            G[i + m].push_back({u, w});
        }
    }
    for (int i = 1; i <= n; i++) dijkstra(i + m, i);
    while (q--) { 
        ll x, y, ans = LMX; cin >> x >> y; 
        for (auto u : G[x]) { for (auto v : G[y]) ans = min(ans, DIS(u.to - m, v.to - m) + u.w + v.w); }
        ans += w[x] + w[y];
        cout << ans << '\n';
    }
    return 0;
}