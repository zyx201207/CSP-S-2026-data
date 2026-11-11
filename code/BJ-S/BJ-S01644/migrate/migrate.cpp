#include<bits/stdc++.h>
using namespace std;
int c,t,x[5555],dp[5555][5555];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        memset(dp,0,sizeof(dp));
        int n,d;
        cin>>n>>d;
        for(int j=1;j<=n;j++)cin>>x[j];
        for(int j=1;j<=n;j++){
            for(int k=j-1;k>=1;k--){
                if(x[j]-x[k]<=d)dp[k][j]=1;
                else{
                    for(int r=k+1;r<j;r++)dp[k][j]+=dp[k][r]*dp[r][j];
                }
            }
        }int ans=0;
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(dp[j][k]==2)ans++;
            }
        }cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
