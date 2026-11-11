#include <bits/stdc++.h>
using namespace std;

#define int long long

struct edge {
    int u, v;
};

const int inf = 1e15 + 7;
vector <edge> g[200010];
int w[500010];
int dist[2010][2010];
bool vis[2010];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;

    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            g[a].push_back({m + i, t});
            g[m + i].push_back({a, t});
        }
    }
    for(int i = 1; i <= m; i++) {
        priority_queue <pair <int, int>, vector <pair <int, int > >, greater <pair <int, int> > > q;
        for(int j = 1; j <= 2010; j++) {
            dist[i][j] = inf;
        }
        memset(vis, 0, sizeof(vis));
        dist[i][i] = 0;
        q.push({0, i});
        while(!q.empty()) {
            pair <int, int> p = q.top();
            q.pop();
            if(vis[p.second]) continue;
            vis[p.second] = 1;
            for(int j = 0; j < g[p.second].size(); j++) {
                int to = g[p.second][j].u;
                if(dist[i][to] > dist[i][p.second] + g[p.second][j].v) {
                    dist[i][to] = dist[i][p.second] + g[p.second][j].v;
                    q.push({dist[i][to], to});
                }
            }
        }
    }
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << w[u] + dist[u][v] + w[v] << endl;
    }
}
