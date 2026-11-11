#include<bits/stdc++.h>
using namespace std;
int c,t,n,x[3000000],dp[3000][30000],dps[3000][30000],ans,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int o=1;o<=t;o++){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=10000;
                dps[i][j]=10000;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>x[i];
            dp[i][i]=0;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dp[i][j]==dp[i][k]+dp[k+1][j]) dps[i][j]++;
                    int a=dp[i][j];
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                    if(a!=dp[i][j]) dps[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dps[i][j]==2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
