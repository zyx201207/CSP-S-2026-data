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

int c, t;
int n, d;
int a[2000005];
int dp[305][305];
int cnt[305][305];

signed main() {
    //freopen("migrate4.in", "r", stdin);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = read(); t = read();
    while(t--) {
        n = read(); d = read();
        for (int i = 1; i <= n; i++) a[i] = read();
        //if (n <= 300) {
            memset(dp, 0x3f, sizeof(dp));
            memset(cnt, 0, sizeof(cnt));
            for (int i = 1; i <= n; i++) dp[i][i] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; a[j] - a[i] <= d && j <= n; j++) {
                    if (dp[i][j] == 0) continue;
                    dp[i][j] = dp[j][i] = 1;
                    cnt[i][j]++; cnt[j][i]++;
                }
            }
            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (dp[i][k] > 1e18 || dp[k][j] > 1e18) continue;
                        int ndis = dp[i][k] + dp[k][j];
                        if (dp[i][j] > ndis) {
                            dp[i][j] = ndis;
                            cnt[i][j] = cnt[i][k] * cnt[k][j];
                        }
                        else if (dp[i][j] == ndis) {
                            cnt[i][j] += cnt[i][k] * cnt[k][j];
                        }
                    }
                }
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (cnt[i][j] == 2) ans++;
                }
            }
            cout << ans << "\n";
        //}
    }
    return 0;
}
