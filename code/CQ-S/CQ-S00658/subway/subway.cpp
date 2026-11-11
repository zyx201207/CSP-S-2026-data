#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 500;
int c, n, m, d, q;
vector<pair<int, int> > G[500000 + 5];
ll dp[MAXN + 5][MAXN + 5];
int w[500000 + 5];
int read() {
    int x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++i) {
        w[i] = read();
    }
    for (int i = 1; i <= n; ++i) {
        int k; scanf("%d", &k);
        for (int j = 1; j <= k; ++j) {
            int a = read(), t = read();
            G[a].push_back({i, t});
        }
    }
    // cerr<<42342423<<endl;
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int i = 1; i <= n; ++i) dp[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        int len = G[i].size();
        for (int a = 0; a < len; ++a) {
            for (int b = a + 1; b < len; ++b) {
                int x = G[i][a].first, y = G[i][b].first;
                dp[x][y] = min(dp[x][y], (ll)G[i][a].second + G[i][b].second);
                dp[y][x] = dp[x][y];
            }
        }
    }
    // cerr<<42342423<<endl;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                dp[j][i] = dp[i][j];
            }
        }
    }
    // cerr<<42342423<<endl;
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        ll ans = dp[0][0];
        for (auto i : G[x]) {
            for (auto j : G[y]) {
                ans = min(ans, dp[i.first][j.first] + i.second + j.second);
            }
        }
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
    // cerr<<clock();
    return 0;
}