#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500010];
long long maxn = 1;
long long dp[500010];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = n; i > 1; i--) {
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= i; j++) {
            dp[j] = a[i] - a[j];
        }
        sort(dp, dp + i + 1);
        long long sum = 0, tmp = 0;
        for (int j = 1; j <= i; j++) {
            if (sum + dp[j] <= m) {
                sum += dp[j];
                tmp++;
            } else {
                break;
            }
        }
        maxn = max(maxn, tmp);
    }
    cout << maxn << endl;
    return 0;
}
