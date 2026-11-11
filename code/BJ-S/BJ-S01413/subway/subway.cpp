#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct cycle {
    vector<pair<int, int>> nxt;
};
int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int z, n, m, d, q, x, y;
    cin >> z >> n >> m >> d >> q;
    vector<int> w(m+1);
    vector<vector<pair<int, int>>> c(m+1);
    for (int i = 1; i <= m; i++) cin >> w[i];
    vector<int> k(n+1);
    vector<vector<int>> a(n+1);
    vector<vector<int>> t(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        a[i].resize(k[i]);
        t[i].resize(k[i]);
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            c[a[i][j]].push_back({i, j});
        }
    }
    vector<cycle> cy(m+1);
    for (int i = 1; i <= m; i++) {
        for (auto u : c[i]) {
            for (auto v : c[i]) {
                cy[u.first].nxt.push_back ({v.first, t[u.first][u.second]+t[v.first][v.second]});
                cy[v.first].nxt.push_back ({u.first, t[u.first][u.second]+t[v.first][v.second]});
            }
        }
    }
    vector<vector<int>> dist(m+1, vector<int>(m+1, 0x3f3f3f3f));
    for (int i = 1; i <= m; i++) {
        for (auto j : cy[i].nxt) {
            dist[i][j.first] = j.second;
        }
    }
    for (int i = 1; i <= m; i++) dist[i][i] = 0;
    for (int k = 1; k <= m; k++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                dist[i][j] = min (dist[i][j], dist[i][k]+dist[k][j]);
    while (q--) {
        cin >> x >> y;
        int ans = 0x3f3f3f3f;
        for (auto b : c[x]) {
            for (auto e : c[y]) {
                ans = min(ans, dist[b.first][e.second]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
