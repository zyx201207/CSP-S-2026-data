# include <bits/stdc++.h>
using namespace std;
# define int long long
const int MAXN = 5e2 + 10, MAXM = 5e5 + 10;
int c, n, m, d, q;
int w[MAXM], g[MAXN][MAXN];
vector <pair <int, int> > vec[MAXM];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x, y;
            cin >> x >> y;
            vec[x].push_back({i, y});
        }
    }
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= m; i++) {
        for (auto [x, y] : vec[i]) {
            for (auto [a, b] : vec[i]) {
                g[x][a] = min(g[x][a], y + b);
            }
        }
    }
    // for (int i = 1;i <= m; i++) {
    //     for (auto [x, y] : vec[i]) {
    //         cout << x << " " << y << endl ;
    //     }
    //     cout << endl ;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << g[i][j] << " " ;
    //     }
    //     cout << endl ;
    // }
    for (int i = 1;i <= n; i++) g[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << 0 << endl ;
            continue;
        }
        int ans = 1e18;
        for (auto [a, b] : vec[x]) {
            for (auto [c, d] : vec[y]) {
                ans = min(ans, g[a][c] + b + d);
            }
        }
        cout << ans + w[x] + w[y] << endl ;
    }
    return 0;
}
