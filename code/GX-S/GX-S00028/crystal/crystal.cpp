#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int dp[50005][5005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        for(long long j=2;j<=m;j++){
            dp[i][j]=a[i]+max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m];
}
