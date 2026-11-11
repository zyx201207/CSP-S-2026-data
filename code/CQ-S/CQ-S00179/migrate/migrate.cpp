// Author: lzm0107
// 18:12

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    for (int tid = 1; tid <= t; tid++) {
        int n;
        cin >> n;
        long long d;
        cin >> d;
        vector<long long> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<int> rig(n), lef(n);
        queue<int> que;
        for (int i = 0; i < n; i++) {
            while (!que.empty() && x[que.front()] + d < x[i]) {
                rig[que.front()] = i - 1;
                que.pop();
            }
            que.push(i);
        }
        while (!que.empty()) { rig[que.front()] = n - 1; que.pop(); }
        for (int i = n - 1; i >= 0; i--) {
            while (!que.empty() && x[que.front()] - d > x[i]) {
                lef[que.front()] = i + 1;
                que.pop();
            }
            que.push(i);
        }
        while (!que.empty()) { lef[que.front()] = 0; que.pop(); }
        long long ans = 0;
        vector<array<int, 3>> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[rig[i]];
            if (rig[rig[i]] != rig[i]) {
                int r0 = rig[i], r1 = rig[r0], l0 = lef[r1];
                if (l0 == r0 - 1) {
                    dp[i][2] = dp[i][0];
                    dp[i][1] = 0;
                    dp[i][0] = 0;
                } else if (l0 < r0 - 1) {
                    dp[i][2] = 0;
                    dp[i][1] = 0;
                    dp[i][0] = 0;
                }
            }
            ans += dp[i][1] + dp[i][2];
            if (i < rig[i]) {
                if (lef[rig[i] - 1] == i) {
                    dp[i][1] += dp[i][2];
                }
                dp[i][2] = 0;
            }
            int m0 = (i >= 2 ? max(i, rig[i - 2]) : i);
            int m1 = (i >= 1 ? max(i, rig[i - 1]) : i);
            if (m1 == rig[i]) {
                dp[i][0] += m1 - m0;
            } else {
                dp[i][2] += m1 - m0;
                dp[i][0] += rig[i] - m1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}