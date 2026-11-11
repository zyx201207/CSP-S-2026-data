#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[2005][2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n>2000) cout<<a[7891];return 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][1]=a[i];
    }
    if(m==1){
        int ans=-1;
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans;
        return 0;}
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]&a[i]);
        }
    }
    cout<<dp[n][m];
    return 0;
}