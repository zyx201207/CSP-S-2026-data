#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[100005] , dp[1005][1005] , f[1005][1005];
signed main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    int c , t;
    cin >> c >> t;
    while (t--){
        int n , d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        memset(dp , 63 , sizeof(dp));
        memset(f , 0 , sizeof(f));
        for (int i = 1; i <= n; i++) dp[i][i] = 1 , f[i][i] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n && x[j] - x[i] <= d; j++){
                f[i][j] = 1;
                dp[i][j] = 2;
            }
        }
        for (int l = 2; l <= n; l++){
            for (int i = 1; i <= n; i++){
                int j = i + l - 1;
                for (int k = i; k < j; k++){
                    for (int q = k + 1; q < j && x[q] - x[k] <= d; q++){
                        if (dp[i][j] > dp[i][k] + dp[q][j]){
                            dp[i][j] = dp[i][k] + dp[q][j];
                            f[i][j] = f[i][k] * f[q][j];
                            //if (i == 1 && j == 4) cout << f[i][k] << " " << f[q][j] << "\n";
                        }
                        else if(dp[i][j] == dp[i][k] + dp[q][j]){
                            f[i][j] += f[i][k] * f[q][j];
                            //if (i == 1 && j == 4) cout << i << k << q << j << "\n";
                        }
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                if (f[i][j] == 2) cnt++;
                //cout << f[i][j] << " ";
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
