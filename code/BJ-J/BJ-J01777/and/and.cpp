#include <bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005],dp[2005][2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i],dp[1][i]=a[i];
    for(int j=2;j<=m;++j){
        for(int i=1;i<=n;++i){
            int res=0;
            for(int k=1;k<i;++k){
                res=max(dp[j-1][k]&a[i],res);
            }
            dp[j][i]=max(res,dp[j][i]);
        }
    }
    for(int i=1;i<=n;++i) ans=max(ans,dp[m][i]);
    cout<<ans;
    cout.flush();
    return 0;
}