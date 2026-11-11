#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int a[2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1][1]=a[1];
    for(int i=1;i<=n;i++) dp[i][1]=a[i];
    for(int i=1;i<=n;i++){
        for(int j=2;j<=min(i,m);j++){
            dp[i][j]=max({dp[i-1][j],dp[i-1][j-1]&a[i]});
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<dp[n][m];
    return 0;
}