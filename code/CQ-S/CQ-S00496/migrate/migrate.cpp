#include <bits/stdc++.h>

using namespace std;

int T;
int n;
long long d;
long long a[2000005];
int dp[2000005];
int f[2000005];
int s[2000005];
int p[2000005];

void Main() {
    cin >> n >> d;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        p[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
        // cout << p[i] << " ";
    }
    // cout << endl;
    long long ans = 0;
    for (int k = 1; k <= n; k ++) {
        dp[k] = 1;
        f[k] = 0;
        s[k - 1] = 0;
        s[k] = 1;
        int lst = k;
        for (int i = k + 1; i <= n; i ++) {
            if (p[i] == i) break;
            int tt = max(p[i], k);
            f[i] = f[tt] + 1;
            if (f[i] != f[i - 1]) lst = i - 1;
            // if (lst <= tt) lst = i;
            dp[i] = min(3, s[lst] - s[tt - 1]);
            s[i] = s[i - 1] + dp[i];
            // cout << k << " " << i << ": " << dp[i] << " " << f[i] << endl;
            // dp[i] = 0;
            // int t = 0x3f3f3f3f;
            // for (int j = i; j >= k; j --) {
            //     if (a[i] - a[j] > d) break;
            //     t = f[j];
            // }
            // f[i] = t + 1;
            // for (int j = i; j >= k; j --) {
            //     if (a[i] - a[j] > d) break;
            //     if (f[j] == t) dp[i] += dp[j];
            // }
            // if (dp[i] > 3) dp[i] = 3;
            if (dp[i] == 2) ans ++;
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    int t;
    cin >> T >> t;
    while (t --) Main();
    return 0;
}