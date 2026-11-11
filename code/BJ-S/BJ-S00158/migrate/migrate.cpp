#include <bits/stdc++.h>
#define N 510
#define int long long
using namespace std;
int a[N], dp[N][N], f[N][N];
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, q;
    cin >> c >> q;
    while(q--){
        int n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = 1e18;
                f[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i][i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j){
                    continue;
                }
                if(abs(a[i] - a[j]) <= d){
                    dp[i][j] = 1;
                }
            }
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(i == j || j == k || i == k){
                        continue;
                    }
                    if(dp[i][k] + dp[k][j] < dp[i][j]){
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                    if(dp[i][k] + dp[k][j] == dp[i][j]){
                        f[i][j]++;
                    }
                }
            }
        }
        int answer = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(f[i][j] == 2){
                    answer++;
                }
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
