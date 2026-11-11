#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200005];
void solvem1(){
    int maxn = -1e18;
    for (int i = 1; i <= n; i++) maxn = max(maxn, a[i]);
    cout << maxn << endl;
}
void solvemn(){
    int ans = a[1];
    for (int i = 2; i <= n; i++) ans &= a[i];
    cout << ans << endl;
}
void solvem2(){
    int maxn = -1e18;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) continue;
            maxn = max(maxn, a[i] & a[j]);
        }
    }
    cout << maxn << endl;
}
void solve20(){
    int dp[2][200005];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i % 1][j] = dp[(i - 1) % 1][j];
            dp[i % 1][j] = max(dp[(i - 1) % 1][j], dp[i % 1][j - 1] & a[i]);
        }
    }
    cout << max(dp[1][m], dp[0][m]) << endl;
}
signed main(){
    //freopen("and.in", "r", stdin);
    //freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (m == 1) solvem1();
    else if (m == n) solvemn();
    else if (m == 2) solvem2();
    else solve20();
    return 0;
}
