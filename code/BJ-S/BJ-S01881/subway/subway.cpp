#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 5e5 + 10, N = 1010;

struct Node {
    int to, dis;
    inline bool operator<(const Node& o) const {
        return dis > o.dis;
    }
};

vector<Node> e[N];
int w[M];
int dist[N];
bool vis[N];

inline int Dijkstra(int s, int t) {
    memset(vis, false, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<Node> q;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().to, dis = q.top().dis;
        q.pop();
        dist[u] = dis;
        vis[u] = 1;
        for (auto c : e[u]) {
            if (!vis[c.to] && dis + c.dis < dist[c.to]) {
                q.push({c.to, dis + c.dis});
            }
        }
    }
    return dist[t];
}

int c, n, m, d, q;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        int prev = 0;
        for (int j = 1; j <= k; ++j) {
            int u, w;
            cin >> u >> w;
            u += 500;
            e[u].push_back({i, w});
            e[i].push_back({u, w});
            if (prev) {
                e[u].push_back({prev, 0});
            }
            prev = u;
        }
    }
    for (int i = 1; i <= q; ++i) {
        int x, y;
        cin >> x >> y;
        cout << w[x] + Dijkstra(x + 500, y + 500) + w[y] << '\n';
    }
    return 0;
}