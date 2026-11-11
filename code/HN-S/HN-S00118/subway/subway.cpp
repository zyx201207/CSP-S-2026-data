#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 510, M = 5e5 + 10;
int c, n, m, d, q, dis[N][N], w[M];
vector<pair<int, int> > id[M];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dis[i][j] = 1e18;
        }
        dis[i][i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int x, t;
            cin >> x >> t;
            for(int k = 0; k < id[x].size(); k++) {
                int y = id[x][k].first, w = id[x][k].second;
                dis[i][y] = dis[y][i] = t + w;
            }
            id[x].push_back({i, t});
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        int ans = 1e18;
        for(int i = 0; i < id[x].size(); i++) {
            for(int j = 0; j < id[y].size(); j++) {
                ans = min(ans, dis[id[x][i].first][id[y][j].first] + id[x][i].second + id[y][j].second);
            }
        }
        cout << ans + w[x] + w[y] << "\n";
    }

    return 0;
}