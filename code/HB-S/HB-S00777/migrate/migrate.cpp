#include<bits/stdc++.h>
using namespace std;
long long dp[5002][5002],num,ans;
long long dis[5002];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int c,T,n,m,lj;
    cin>>c>>T,lj=T-1;
    while(T--){
        cin>>n>>m,ans=0;
        for(int i=1;i<=n;i++)cin>>dis[i],dp[i+1][i]=1;
        for(long long l=1;l<n;l++){
            for(long long i=l+2;i<=n;i++){
                num=1,dp[i][l]=i-l;
                for(long long j=i-1;dis[i]-dis[j]<=m&&j>=l;j--){
                    if(dp[i][l]==dp[j][l]+1)++num;
                    if(dp[i][l]>dp[j][l]+1){
                        dp[i][l]=dp[j][l]+1,num=1;
                    }
                }
                if(num==2)++ans;
            }
        }
        cout<<ans<<'\n';
    }
    return ( 0 - 0 );
}