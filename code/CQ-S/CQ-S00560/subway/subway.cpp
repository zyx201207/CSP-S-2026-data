#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 500 + 5;
const int M = 5e5 + 5;
ll w[M], dp[N][N];
vector<pair<int, ll>> lis[M];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        dp[i][i] = 0;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            lis[a].push_back({i, t});
        }
    }
    for (int i = 1; i <= m; i++) {
        for (auto s : lis[i]) {
            for (auto t : lis[i]) {
                if (s == t) continue;
                // cerr << i << ' ' << s.first << ' ' << s.second << '\n';
                dp[s.first][t.first] = min(dp[s.first][t.first], s.second + t.second);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = 1e18;
        for (auto s : lis[x]) {
            for (auto t : lis[y]) {
                // cerr << s.first << ' ' << t.first << '\n';
                ans = min(ans, dp[s.first][t.first] + s.second + t.second + w[x] + w[y]);
            } 
        }
        cout << ans << '\n';
    }
    return 0;
}