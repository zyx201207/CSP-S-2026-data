#include<bits/stdc++.h>
#define LL long long
#define PLL pair<LL, LL>
#define PLI pair<LL, int>
#define PIL pair<int, LL>
#define PII pair<int, int>
using namespace std;
const int N = 2e6;
int n, nxt[N + 5];
LL d, a[N + 5], dp[N + 5][4], ans;

inline void solve() {
    cin >> n >> d; ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    nxt[n] = n + 1;
    int t = n;
    for (int i = n - 1; i >= 1; --i) {
        while (i < t && a[i] + d < a[t]) t--;
        nxt[i] = t;
    }
    dp[n][1] = dp[n][2] = dp[n][3] = 0;
    for (int i = n - 1; i >= 1; --i) {
        if (nxt[i] == i) dp[i][1] = 0;
        else if (i + 1 == nxt[i]) dp[i][1] = dp[nxt[i]][1] + 1;
        else {
            if (nxt[nxt[i]] == nxt[nxt[i] - 1]) dp[i][1] = nxt[i] - i;
            else dp[i][1] = dp[nxt[i]][1] + nxt[i] - i - (nxt[nxt[i] - 1] - nxt[i]);
        }
        if (i == nxt[i]) dp[i][2] = 0;
        else if (i + 1 == nxt[i]) dp[i][2] = dp[nxt[i]][2] + dp[nxt[i]][3];
        else {
            dp[i][2] = 0;
            if (nxt[nxt[i] - 1] < nxt[nxt[i]] - 1) dp[i][2] = dp[nxt[i]][2] + dp[nxt[i]][3];
            else if (nxt[nxt[i] - 1] < nxt[nxt[i]]) dp[i][2] = dp[nxt[i]][2];
        }
        dp[i][3] == 0;
        if (i == nxt[i]) dp[i][3] = 0;
        else if (i + 1 == nxt[i]) dp[i][3] = 0;
        else if (i + 2 == nxt[i]) {
            dp[i][3] = 0;
            if (nxt[nxt[i]] == nxt[nxt[i] - 1]) dp[i][3] = dp[nxt[i]][1];
            else dp[i][3] = nxt[nxt[i] - 1] - nxt[i];
        } else {
            dp[i][3] = 0;
            if (nxt[nxt[i]] == nxt[nxt[i] - 1] && nxt[nxt[i]] != nxt[nxt[i] - 2])
                dp[i][3] = dp[nxt[i]][1] - (nxt[nxt[i] - 2] - nxt[i]);
            else dp[i][3] = nxt[nxt[i] - 1] - nxt[nxt[i] - 2];
        }
        ans += dp[i][2] + dp[i][3];
        // cerr << i << ": " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << "\n";
    }
    cout << ans << "\n";
}
signed main() {
    // freopen("migrate6.in", "r", stdin);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int cc, tt = 1;
    cin >> cc >> tt;
    while (tt--) solve();
    return 0;
}