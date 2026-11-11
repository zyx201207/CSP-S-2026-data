#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int a[N], dp[N][N], sum[N][N];
void Solve() {
    int n, d, res = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int s = 1; s <= n; s++) {
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));
        dp[s][0] = sum[s][0] = 1;
        int p = s;
        for(int i = s + 1; i <= n; i++) {
            while(a[i] - a[p] > d && i >= p) p++;
            bool flag = 0;
            for(int j = 1; j <= n; j++) {
                dp[i][j] += sum[i - 1][j - 1] - sum[p - 1][j - 1];
                sum[i][j] = sum[i - 1][j] + dp[i][j];
                if(!flag && dp[i][j] == 2) res++, flag = 1;
            }
        }
    }
    cout << res << endl;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--) {
        Solve();
    }
    return 0;
}