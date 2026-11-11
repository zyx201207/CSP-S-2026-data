#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace stdp {
    const int N = 300;
    int n, d, x[N + 5];
    pair<int, int> dp[N + 5];
    void main() {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) dp[j] = {1e18, 0};
            dp[i] = {0, 1};
            for (int j = i; j <= n; j++) {
                int l = j;
                while (l >= i && x[j] - x[l] <= d) l--;
                for (int k = l + 1; k < j; k++) dp[j].first = min(dp[j].first, dp[k].first + 1);
                for (int k = l + 1; k < j; k++) {
                    if (dp[j].first == dp[k].first + 1) {
                        dp[j].second += dp[k].second;
                        dp[j].second = min(dp[j].second, 3ll);
                    }
                }
            }
            for (int j = i; j <= n; j++) {
                // cout << dp[j].first << " " << dp[j].second << "\n";
                if (dp[j].second == 2) res++;
            }
            // cout << "\n";
        }
        cout << res << "\n";
    }
}

namespace sol2 {
    const int N = 2e6;
    int n, d, x[N + 5];
    void main() {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        if (n == 1) {
            cout << 0 << "\n";
            return;
        }
        int k = d / (x[2] - x[1]) + 1;
        if (k == 1 || k == 2) {
            cout << 0 << "\n";
            return;
        }
        cout << max(0ll, n - 2 * k + 3) << "\n";
    }
}

signed main() {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int c, t = 1;
    cin >> c >> t;

    if (c == 11 || c == 12) {
        while (t--) sol2::main();
        return 0;
    }

    while (t--) stdp::main();
    return 0;
}

// clear!!!!!!!
