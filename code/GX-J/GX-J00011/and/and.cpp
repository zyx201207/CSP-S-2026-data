#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const bool debug = false;
int n, m;
int a[N];
int dp[N];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(dp, 0xcf, sizeof(dp));
    int pre = a[1];
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[1] = max(dp[1], a[i]);
        pre &= a[i];
        for (int j = min(i, m); j > 1; j--) {
            if (j == i) dp[j] = pre;
            else dp[j] = max(dp[j], dp[j - 1] & a[i]);
            if (debug) cout << i << ' ' << j << ' ' << dp[j] << '\n';
        }
    }
    cout << dp[m];
    return 0;
}
