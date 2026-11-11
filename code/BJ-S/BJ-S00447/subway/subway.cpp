#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

struct Node {
    int v, w;
};

int c, n, m, d, q, w[500005], a[505][500005], t[505][500005];
long long dist[505][505];
vector<Node> pos[500005];

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], (long long) dist[i][k] + dist[k][j]);
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dist, 0x3f, sizeof dist);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j] >> t[i][j];
            pos[a[i][j]].push_back({i, j});
        }
        dist[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int len = pos[i].size();
        for (int u = 0; u < len; u++)
            for (int v = u + 1; v < len; v++) {
                dist[pos[i][u].v][pos[i][v].v] = (long long) t[pos[i][u].v][pos[i][u].w] + t[pos[i][v].v][pos[i][v].w];
                dist[pos[i][v].v][pos[i][u].v] = (long long) t[pos[i][u].v][pos[i][u].w] + t[pos[i][v].v][pos[i][v].w];
            }
    }
    floyd();
    while (q--) {
        int u, v;
        long long ans = 9e18;
        cin >> u >> v;
        for (int i = 0; i < pos[u].size(); i++)
            for (int j = 0; j < pos[v].size(); j++) {
                if (pos[u][i].v == pos[v][j].v)
                    ans = min(ans, (long long) t[pos[u][i].v][pos[u][i].w] + t[pos[v][j].v][pos[v][j].w]);
                ans = min(ans, (long long) t[pos[u][i].v][pos[u][i].w] + t[pos[v][j].v][pos[v][j].w] + dist[pos[u][i].v][pos[v][j].v]);
            }
        cout << (long long) w[u] + w[v] + ans << endl;
    }
    return 0;
}
