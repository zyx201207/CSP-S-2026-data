#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int M = 5e5 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> PII;
vector<pair<int, int> > g[505];
vector<int> lnk[M];
int c, n, m, d, q;
int w[M];//
int val[505][M];
bool vis[505];
int dis[505][505];
void dijk(int s) {
    priority_queue<PII, vector<PII>, greater<PII> > q;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        dis[s][i] = INF;
    }
    dis[s][s] = 0;
    q.emplace(0, s);
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 0;
        int len = g[u].size();
        for (int i = 0; i < len; ++i) {
            int v = g[u][i].first, c = g[u][i].second;
            if(dis[s][u] + c < dis[s][v]) {
                dis[s][v] = dis[s][u] + c;
                q.emplace(dis[s][v], v);
            }
        }
    }
}


signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1, k; i <= n; ++i) {
        cin >> k;
        for (int j = 1, a, t; j <= k; ++j) {
            cin >> a >> t;
            val[i][a] = t;//min
            lnk[a].emplace_back(i);
        }
    }
    for (int i = 1; i <= m; ++i) {
        int len = lnk[i].size();
        for (int j = 0; j < len; ++j) {
            for (int k = j + 1; k < len; ++k) {
                int u = lnk[i][j];
                int v = lnk[i][k];
                if(val[u][i] && val[v][i]) {
                    g[u].emplace_back(v, val[u][i] + val[v][i]);
                    g[v].emplace_back(u, val[u][i] + val[v][i]);
                }
            }
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (auto v : g[i]) cout << v.first << ' ' << v.second << ' ';
    //     cout << '\n';
    // }
    for (int i = 1; i <= n; ++i) {
        dijk(i);
    }
    int x, y;
    while(q--) {
        cin >> x >> y;
        int res = INF;
        int lx = lnk[x].size();
        int ly = lnk[y].size();
        for (int i = 0; i < lx; ++i) {
            for (int j = 0; j < ly; ++j) {
                int u = lnk[x][i];
                int v = lnk[y][j];
                if(dis[u][v] != INF) {
                    res = min(res, dis[u][v] + val[u][x] + val[v][y]);
                }
            }
        }
        cout << w[x] + res + w[y] << '\n';
    }
    return 0;
}