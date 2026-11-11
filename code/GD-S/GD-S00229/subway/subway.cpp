#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,D=25,Q=1e5+5,inf=1e18;
int c,n,m,d,q,w[M];
vector<array<int,2>>sta[M];
int dis[N][N];
inline void floyd(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=i!=j?inf:0;
    for(int i=1;i<=m;i++)
        for(auto [lx,tx]:sta[i])
            for(auto [ly,ty]:sta[i])
                dis[lx][ly]=min(dis[lx][ly],tx+ty);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,u,t;j<=k;j++)
            cin>>u>>t,sta[u].push_back({i,t});
    }
    floyd();
    for(int x,y,ans;q--;){
        cin>>x>>y,ans=inf;
        for(auto [lx,tx]:sta[x])
            for(auto [ly,ty]:sta[y])
                ans=min(ans,tx+ty+dis[lx][ly]);
        cout<<ans+w[x]+w[y]<<'\n';
    }
}