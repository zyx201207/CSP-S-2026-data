#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505, M = 500005, D = 405;
ll c, n, m, d, q, w[M], k[N];
vector<ll> ln[M], tim[M];
ll dis[N][N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = 0x3f3f3f3f3f3f3f3fll;
        }
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            int x, y;
            cin >> x >> y;
            ln[x].push_back(i);
            tim[x].push_back(y);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < ln[i].size(); j++) {
            int x = ln[i][j];
            for (int p = 0; p < j; p++) {
                int y = ln[i][p];
                dis[x][y] = dis[y][x] = min(dis[x][y], tim[i][j] + tim[i][p]);
            }
        }
    }
    for (int p = 1; p <= n; p++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][p] + dis[p][j]);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = 0x3f3f3f3f3f3f3f3fll;
        for (int i = 0; i < ln[x].size(); i++) {
            for (int j = 0; j < ln[y].size(); j++) {
                ans = min(ans, dis[ln[x][i]][ln[y][j]] + tim[x][i] + tim[y][j]);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}