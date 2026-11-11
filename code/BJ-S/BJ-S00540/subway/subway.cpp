// 100 pts

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;

    vector<int> w(m + 1);
    for (int i = 1; i <= m; ++i)
        cin >> w[i];

    vector<vector<pair<int, int>>> stops(m + 1);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        while (k-- > 0) {
            int a, t;
            cin >> a >> t;
            stops[a].emplace_back(i, t);
        }
    }

    vector<vector<i64>> dist(n + 1, vector<i64>(n + 1, INF));
    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;
    for (const auto& stop : stops) {
        for (int i = 0, k = stop.size(); i < k; ++i) {
            int u = stop[i].first;
            for (int j = i + 1; j < k; ++j) {
                int v = stop[j].first;
                dist[u][v] = dist[v][u] = min<i64>(dist[u][v], stop[i].second + stop[j].second);
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    while (q-- > 0) {
        int x, y;
        cin >> x >> y;

        i64 ans = INF;
        for (const auto& line1 : stops[x]) {
            for (const auto& line2 : stops[y])
                ans = min(ans, dist[line1.first][line2.first] + line1.second + line2.second);
        }

        cout << ans + w[x] + w[y] << '\n';
    }
    
    cout << flush;
    return 0;
}