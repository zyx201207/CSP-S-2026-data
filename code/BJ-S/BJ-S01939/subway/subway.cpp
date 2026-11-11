#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5, MAXM = 5e5 + 5;
int c, n, m, d, q, x, y, w[MAXM], k[MAXN], a, t[MAXN][MAXM], dist[MAXM];
vector<pair<int, int> > mp[MAXM];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push({0, x});
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[x] = 0;
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if (d != dist[u]) continue;
        for (pair<int, int> to : mp[u]) {
            int v = to.first, w = to.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                q.push({dist[v], v});
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        if (k[i] == 1) continue;
        for (int j = 1; j <= k[i]; j++) {
            cin >> a >> t[i][j];
            mp[i].push_back({a, t[i][j] + t[j][j]});
        }
    }
    while (q--) {
        cin >> x >> y;
        dijkstra();
        cout << dist[y] + w[x] + w[y] + t[x][x] << '\n';
    }
    return 0;
}
