#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int n, D, a[N], fa[N], sz[N], dp[N][2], dp1[N];
vector<int> g[N];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    // freopen("1.err", "w", stderr);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int C, TT;
    cin >> C >> TT;
    while (TT--) {
        for (int i = 0; i <= n + 1; i++) {
            g[i].clear();
            sz[i] = 0, fa[i] = 0;
            dp[i][0] = dp[i][1] = 0, dp1[i] = 0;
        }
        cin >> n >> D;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int j = n;
        for (int i = n; i >= 1; i--) {
            while (j > i && a[j] - a[i] > D) {
                j--;
            }
            if (i == j) {
                g[n + 1].push_back(i);
                fa[i] = j; 
            } else {
                g[j].push_back(i);
                fa[i] = j;
            }
            //  cerr << i << " " << j << "\n";
        }
        int ans = 0;
        for (int i = 1; i <= n + 1; i++) {
            // sz[i]++, sz[fa[i]] += sz[i];
            if (i == n + 1) break;
            dp[i][0] = 1;
            for (auto j : g[i]) {
                int l = max(j + 1, fa[j - 1] + 1);
                int r = i, flag = 0;
                if (l <= r) {
                    ans += (r - l + 1) * dp[j][1];
                    // cerr << i << " " << j << " " << (r - l + 1) * dp[j][1] << "!\n";
                    dp[i][0] += dp[j][0] - 1;
                    dp[i][1] += dp[j][1];
                    flag = 1;
                }
                l = max(j + 1, (j == 1 ? 0 : fa[j - 2]) + 1);
                r = fa[j - 1];
                if (l <= r) {
                    ans += (r - l + 1) * (dp1[j] - 1);
                    //  cerr << i << " " << j << " " << (r - l + 1) * (dp1[j] - 1) << "!!\n";
                    // if (fa[i - 1] != i && l <= i - 1 && i - 1 <= r) {
                    //     dp1[i] -= (dp1[j] - 1);
                    // }
                    if (l <= i && i <= r) dp[i][1] += dp1[j] - 1;
                    else {
                        int l1 = j + 1, r1 = fa[j - 1];
                        if (l1 <= i - 1 && i - 1 <= r1) {
                            dp1[i] -= (dp[j][0] - 1);
                            // assert(fa[j - 1] == i - 1);
                            // cerr << "@";
                        }
                    }
                } else {
                    int l1 = j + 1, r1 = fa[j - 1];
                    if (l1 <= i - 1 && i - 1 <= r1 && flag) {
                        dp1[i] -= (dp[j][0] - 1);
                        // assert(fa[j - 1] == i - 1);
                        // cerr << "@";
                    }
                }
                dp[i][0]++;
            }
            dp1[i] += dp[i][0];
            //  cerr << i << " " << dp1[i] << " " << dp[i][0] << "\n"; 
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
2

0 1
6 3
0 1 2 3 4 7
0

0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32

7
 */
