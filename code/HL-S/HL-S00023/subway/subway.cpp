#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
typedef long long ll;
const int M=5e5+10,N=5e2+10,D=25;
int c,n,m,d,q;
int w[M];
vector<pair<int,int> >t[M];
ll dp[N][N];
vector<int>g[N];
void add(int u,int v,ll w){
    dp[u][v]=min(dp[u][v],w);
    dp[v][u]=dp[u][v];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1,a,b;j<=k;j++){
            cin>>a>>b;
            t[a].push_back({i,b});
        }
    }for(int i=1;i<=m;i++)
        for(int j=0;j<t[i].size();j++)
            for(int k=j+1;k<t[i].size();k++)
                add(t[i][j].first,t[i][k].first,(ll)t[i][j].second+t[i][k].second);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i-1;k<=n;k++){
                dp[i][j]=min(dp[i][j],dp[k][i]+dp[k][j]);
                dp[j][i]=dp[i][j];
            }

        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=9e18;
        for(auto i:t[x])for(auto j:t[y])ans=min(ans,dp[i.first][j.first]+i.second+j.second);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
