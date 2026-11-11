#include<bits/stdc++.h>
using namespace std;
long long hzb[100010];
int dp[500][500],ljs[500][500];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>hzb[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ljs[i][j]=0;
                dp[i][j]=2e9;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(abs(hzb[j]-hzb[i])<=d){
                    dp[i][j]=dp[j][i]=1;
                    ljs[i][j]=ljs[j][i]=1;
                }
                if(i==j)dp[i][j]=0;
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dp[i][j]=dp[i][k]+dp[k][j]){
                        ljs[i][j]+=ljs[i][k]*ljs[k][j];
                    }else if(dp[i][j]>dp[i][k]+dp[k][j]){
                        dp[i][j]=dp[i][k]+dp[k][j];
                        ljs[i][j]=ljs[i][k]*ljs[k][j];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(ljs[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}