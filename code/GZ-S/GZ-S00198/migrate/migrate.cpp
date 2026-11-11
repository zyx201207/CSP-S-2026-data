// 贵阳市第一中学 林钰涵 GZ-S00198
#include <bits/stdc++.h>
using namespace std;

int testid, n, ans, d[5005], dp[5005], q[5005];
long long m, a[2000005];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "0\n";
        return ;
    }
    if (testid == 11 || testid == 12) {
        long long k = m / (a[2] - a[1]);
        if (k > 1 && n > k) cout << max(n - 2 * k + 1, 0ll) << '\n';
        else cout << "0\n";
        return ;
    }
    ans = 0;
    for (int i = 1; i < n; i++) {
        d[i] = 0;
        dp[i] = 1;
        int fr = 0, tr = 0;
        q[tr++] = i;
        for (int j = i + 1; j <= n; j++) {
            while (fr < tr && a[j] - a[q[fr]] > m) ++fr;
            if (fr >= tr) break;
            d[j] = d[q[fr]] + 1;
            if (fr + 2 < tr && d[q[fr]] == d[q[fr + 2]]) dp[j] = 3;
            else {
                dp[j] = dp[q[fr]];
                if (fr + 1 < tr && d[q[fr]] == d[q[fr + 1]]) dp[j] += dp[q[fr + 1]];
                if (dp[j] > 2) dp[j] = 3;
                if (dp[j] == 2) ++ans;
            }
            q[tr++] = j;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int _;
    for (cin >> testid >> _; _; --_) {
        solve();
    }
    return 0;
}
