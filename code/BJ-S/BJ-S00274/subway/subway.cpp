#include <bits/stdc++.h>
#define int long long
using namespace std;

#define gc getchar_unlocked
inline int read() {
    char c = gc(); int x = 0, f = 1;
    while(c < '0' || c > '9') f *= -1, c = gc();
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = gc();
    return x * f;
}
#undef gc

int c, n, m, d, q;
int w[500005];
int a[500005][25], t[500005][505];
vector<int> acr[500005];
int dp[505][505];
//int T = clock();

signed main() {
    //freopen("subway7.in", "r", stdin);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c=read(); n=read(); m=read(); d=read(); q=read();
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= n; i++) {
        int k = read();
        for (int j = 1; j <= k; j++) {
            a[i][j] = read();
            t[a[i][j]][i] = read();
            acr[a[i][j]].push_back(i);
            for (int p = 0; p < acr[a[i][j]].size() - 1; p++) {
                dp[i][acr[a[i][j]][p]] = min(dp[i][acr[a[i][j]][p]], t[a[i][j]][i] + t[a[i][j]][acr[a[i][j]][p]]);
                dp[acr[a[i][j]][p]][i] = min(dp[acr[a[i][j]][p]][i], t[a[i][j]][i] + t[a[i][j]][acr[a[i][j]][p]]);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] > 1e18 || dp[k][j] > 1e18) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while(q--) {
        int x = read(), y = read(), ans = 1e18;
        for (int i : acr[x]) {
            for (int j : acr[y]) {
                ans = min(ans, dp[i][j] + t[y][j] + t[x][i] + w[x] + w[y]);
            }
        }
        cout << ans << "\n";
    }
    //cout << clock() - T << "\n";
    return 0;
}
