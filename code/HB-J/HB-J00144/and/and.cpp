#include <bits/stdc++.h>
using namespace std;
void open (string s) {
    string in = s + ".in", out = s + ".out";
    freopen (in.c_str(), "r", stdin);
    freopen (out.c_str(), "w", stdout);
}
typedef long long ll;
ll dp[2020][2020], a[200010];
int n, m;
int main () {
    open ("and");
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) dp[1][i] = max(dp[1][i - 1], a[i]);
    for (int i = 2; i <= m; ++i) {
        for (int j = i; j <= n; ++j) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] & a[j]);
        }
    }
    // for (int i = 1; i <= m; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     puts("");
    // }
    cout << dp[m][n];
    return 0;
}
//纳努克，我为你带来烩面了！
