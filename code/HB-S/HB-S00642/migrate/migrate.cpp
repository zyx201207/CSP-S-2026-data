#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5010;
int c,t;
int n,d;
int a[N];
int dp[N][N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        int ans = 0;
        cin >> n >> d;
        memset(dp,0x3f,sizeof(dp));
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                if(a[j] - a[i] <= d) dp[i][j] = 1;
            }
        }
        for(int len = 2;len <= n;len++){
            for(int i = 1,j = i + len - 1;j <= n;i++,j++){
                for(int k = i + 1;k < j;k++){
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i + 3;j <= n;j++){
                int cnt = 0;
                for(int k = i + 1;k < j;k++){
                    if(dp[i][k] + dp[k][j] == dp[i][j]) cnt += 1;
                }
                if(cnt == 2) ans += 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
