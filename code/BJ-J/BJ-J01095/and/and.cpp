#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e6 + 5, N = 1e4 + 10;
int a[maxn];
int dp[N][N];


int f(int a, int b){
    int ans = 0, mi = 1;
    while (max(a, b)){
        if(a % 2 && b % 2){
            ans += mi;
        }
        a /= 2;b /= 2;mi *= 2;
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    if (m == 1){
        int ans = 0;
        for (int i = 1; i <= n; i ++){
            ans = max(ans, a[i]);
        }
        cout << ans;
        return ;
    }else if (m == 2){
        int ans = 0;
        for (int i = 1; i < n; i ++){
            for (int j = i + 1; j <= n; j ++){
                ans = max(ans, f(a[i], a[j]));
            }
        }
        cout << ans;
        return ;
    }else if (m == n){
        int ans = a[1];
        for (int i = 2; i <= n; i ++){
            ans = f(ans, a[i]);
        }
        cout << ans;
        return ;
    }

    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++){
            if (i == 1) dp[1][j] = a[j];
            else{
                for (int k = 1; k <= n; k ++){
                    if (k != j) dp[i][j] = max(dp[i][j], f(dp[i - 1][j], a[k]));
                }
            }

        }
    }

    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++){
            cout << dp[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = max(ans, dp[m][i]);
    }
    cout << ans;

}

signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    solve();

}
