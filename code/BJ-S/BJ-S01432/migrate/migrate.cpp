#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,d,ans=0;
    cin>>n>>d;
    int x[n+1];
    for(int i=1;i<=n;i++)
        cin>>x[i];
    int dp[n+1][n+1];
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[i]<=d){
                dp[i][j]=1;
            }
        }
    }
    for(int len=3;len<=n;len++){
        for(int x=1;x+len-1<=n;x++){
            int y=x+len-1;
            for(int k=x+1;k<y;k++){
                dp[x][y]=min(dp[x][k]+dp[k][y],dp[x][y]);
            }
        }
    }
    int sum[n+1][n+1];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            sum[i][j]=(dp[i][j]<n?1:100000000);
    for(int len=3;len<=n;len++){
        for(int x=1;x+len-1<=n;x++){
            int y=x+len-1;
            int flag=0;
            for(int k=x+1;k<y;k++){
                if(dp[x][k]+dp[k][y]==dp[x][y]){
                    sum[x][y]+=(sum[x][k]*sum[k][y]);
                    flag=1;
                }
            }
            if(flag)
                sum[x][y]--;
        }
    }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            if(sum[i][j]==2)
                ans++;
        }
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>t>>t;
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
