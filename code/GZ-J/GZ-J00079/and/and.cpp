//GZ-J00079 贵阳市新世界学校 李冠儒
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void zf(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,-1e18));
    for(int i=0;i<=n;i++){
        dp[i][0]=pow(2,30)-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
        }
    }
    cout<<dp[n][m]<<'\n';
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    int t=1;
    //cin>>t;
    while(t--)zf();
    return 0;
}
