#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 nums[310];
pair<i64, i64> dp[310][310];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        i64 n, d;
        cin >> n >> d;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = {1LL << 62, 0LL};
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            dp[i][i] = {0LL, 1LL};
        }
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < i; ++k) {
                if (abs(nums[k] - nums[i]) <= d) {
                    for (int j = 0; j < k; ++j) {
                        i64 x = dp[k][j].first, y = dp[k][j].second;
                        if (x + 1 < dp[i][j].first) {
                            dp[i][j] = {x + 1, y};
                        } else {
                            if (x + 1 == dp[i][j].first) {
                                dp[i][j].second += y;
                            }
                        }
                    }
                }
            }
        }
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ans += dp[i][j].second == 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}