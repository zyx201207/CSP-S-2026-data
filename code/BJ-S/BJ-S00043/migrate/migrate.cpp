#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long pos[2000005];
int dp[5005][5005],ans[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i = 1;i <= n;i++){
            scanf("%lld",&pos[i]);
        }
        memset(dp,0x3f,sizeof(dp));
        memset(ans,0,sizeof(ans));
        for(int i = 1;i <= n;i++)dp[i][i] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int k = j;pos[j] - pos[k] <= d && k >= i;k--){
                    if(dp[i][j] == dp[i][k] + 1)ans[i][j] ++;
                    else if(dp[i][j] > dp[i][k] + 1)dp[i][j] = dp[i][k] + 1,ans[i][j] = 0;
                }
            }
        }
        long long out = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                if(ans[i][j] == 1)out++;
            }
        }
        printf("%lld\n",out);
    }
    return 0;
}
