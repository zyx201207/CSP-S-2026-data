#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;
ll n, m, a[N], dp[2][N];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == 1) dp[i%2][j] = a[i];
            dp[i%2][j] = max({(dp[(i+1)%2][j-1] & a[i]), dp[(i+1)%2][j], dp[i%2][j]});
        }
    }
    cout << dp[n%2][m];
    return 0;
}
