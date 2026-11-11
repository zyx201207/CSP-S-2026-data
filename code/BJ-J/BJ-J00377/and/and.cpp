#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> v(n+1);
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    for (int i=1;i<=n;i++){
        cin>>v[i];
        dp[i][1]=v[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;j++){
            for (int k=2;k<=m;k++){
                dp[i][k]=max(dp[i][k],dp[j][k-1]&v[i]);
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        ans=max(ans,dp[i][m]);
    }
    cout<<ans;
    return 0;
}