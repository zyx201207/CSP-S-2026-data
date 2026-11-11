//GZ-S00263 兴义市弘毅中学 韩愈信
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int dp[505][505],w[500005];
vector<array<int,2>> station[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,t;
            cin>>x>>t;
            station[x].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dp[i][j]=1e18;
    }
    for(int i=1;i<=n;i++) dp[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto u:station[i]){
            for(auto v:station[i]){
                if(u[0]!=v[0]){
                    dp[u[0]][v[0]]=min(dp[u[0]][v[0]],u[1]+v[1]);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=k&&j!=k&&i!=j) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for(auto u:station[x]){
            for(auto v:station[y]){
                ans=min(dp[u[0]][v[0]]+u[1]+v[1],ans);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
