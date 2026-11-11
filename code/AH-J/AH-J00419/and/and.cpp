#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200010],dp[200010][2]={0},cs[200010][2]={0},ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[1][0]=0;
    dp[1][1]=a[1];
    for(int i=2;i<=n;i++){
        if(dp[i-1][1]>dp[i-1][0]){
            dp[i][0]=dp[i-1][1];
            if(cs[i-1][0]>0){
                dp[i][1]=dp[i-1][1]&a[i];
            }else{
                dp[i][1]=a[i];
            }
            cs[i][0]=cs[i-1][1];
            cs[i][1]=cs[i-1][1]+1;
        }else{
            dp[i][0]=dp[i-1][0];
            if(cs[i-1][0]>0){
                dp[i][1]=dp[i-1][1]&a[i];
            }else{
                dp[i][1]=a[i];
            }
            cs[i][0]=cs[i-1][0];
            cs[i][1]=cs[i-1][0]+1;
        }
    }for(int i=1;i<=n;i++){
        if(cs[i][0]==m){
            ans=max(ans,dp[i][0]);
        }
        if(cs[i][1]==m){
            ans=max(ans,dp[i][1]);
        }
    }
    cout<<ans;
    return 0;
}
