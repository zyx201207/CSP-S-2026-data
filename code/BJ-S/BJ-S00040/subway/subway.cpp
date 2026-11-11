#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 505;
const int M = N + 5e5 + 5;
int w[M], dist[M], dis[N][N];
bool vis[M];
vector<pii> g[M];
int c, n, m, d, q;
void dij(int s) {
    dis[s-m][s-m] = 0;
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[s] = 0;
    priority_queue<pii> q;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (pii k : g[u]) {
            int v = k.first, w = k.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (v > m) dis[s-m][v-m] = dist[v];
                q.push({-dist[v], v});
            }
        }
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            g[i+m].push_back({a, t});
            g[a].push_back({i+m, t});
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = m+1; i <= m+n; i++) dij(i);
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = 1e18;
        for (pii i : g[x]) {
            int u = i.first - m, w1 = i.second;
            for (pii j : g[y]) {
                int v = j.first - m, w2 = j.second;
                ans = min(ans, w1 + dis[u][v] + w2);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
/*
kao lv mei ge dian hu tong qiu xian lu zhi jian de dijstra
yin wei d minnnnn, keyi yong dis[N][N] fang xia suo you xian lu zhi jian de ju li
sui hou jiu key yi mei ju d lai qiu chu zui xiao
dij(n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            dis[i][j] = dis[1][j] - dis[1][i]
        }
    }
*/
