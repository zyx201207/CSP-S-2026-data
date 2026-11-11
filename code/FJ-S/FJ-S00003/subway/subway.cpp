#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
struct edge{int v,w;};
vector<edge> e[M];
ll dis[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++)
            cin>>a>>t,e[a].push_back({i,t});
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dis[i][j]=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(edge e1:e[i])
            for(edge e2:e[i])
                dis[e1.v][e2.v]=min(dis[e1.v][e2.v],(ll)(e1.w+e2.w));
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;cin>>x>>y;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(edge e1:e[x])
            for(edge e2:e[y])
                ans=min(ans,dis[e1.v][e2.v]+e1.w+e2.w);
        ans+=w[x]+w[y];
        cout<<ans<<'\n';        
    }
}