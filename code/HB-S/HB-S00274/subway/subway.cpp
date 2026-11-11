#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,w[20005],t[20005],a[20005],dp[20005][20005],r[100005][2];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dp[i][j]=1e9;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int k=1;k<=m;k++){
        cin>>x;
        for(int i=1;i<=x;i++)cin>>a[i]>>t[i];
        for(int i=1;i<=x;i++)for(int j=i+1;j<=x;j++){
            dp[a[i]][a[j]]=min(dp[a[i]][a[j]],t[i]+t[j]);
            dp[a[j]][a[i]]=dp[a[i]][a[j]];
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(k!=i&&k!=j&&i!=j&&dp[i][k]&&dp[k][j])dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    for(int i=1;i<=q;i++)cin>>r[i][0]>>r[i][1];
    for(int i=1;i<=q;i++)cout<<dp[r[i][0]][r[i][1]]+w[r[i][0]]+w[r[i][1]]<<'\n';
    return 0;
}
