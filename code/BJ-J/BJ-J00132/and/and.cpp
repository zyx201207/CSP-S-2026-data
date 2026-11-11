#include <bits/stdc++.h>
using namespace std;
#define int int
const int N=2e5+5;
int n,m;
int a[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(2)));//dp[i][j][0/1]:at i,used j(include this),use(or not use) this
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][1][1]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j][0]=max({dp[i][j][0],dp[i-1][j][0],dp[i-1][j][1]});
            dp[i][j][1]=max({dp[i][j][1],dp[i-1][j-1][1]&a[i],dp[i-1][j-1][0]&a[i]});
        }
    }
    cout<<max(dp[n][m][0],dp[n][m][1]);
    return 0;
}
