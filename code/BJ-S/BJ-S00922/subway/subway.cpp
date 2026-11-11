#include<iostream>
#include<queue>
using namespace std;

#define ll long long
const int maxn=500+10,maxm=5e5+10; const ll inf=1e18;
int tc,n,m,d,q,wi[maxm],tot,vis[maxn]; ll dis[maxn][maxn],tdis[maxn][maxn];
vector<pair<int,int>> edges[maxm],grp[maxn];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>tc>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>wi[i];
    for(int i=1;i<=n;i++){
        int ki; cin>>ki;
        for(int j=1;j<=ki;j++){
            int a,t; cin>>a>>t;
            edges[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=inf;
    // md^2
    for(int i=1;i<=m;i++)for(int j=0;j<edges[i].size();j++)for(int k=j+1;k<edges[i].size();k++){
        auto x=edges[i][j],y=edges[i][k];
        dis[x.first][y.first]=min(dis[x.first][y.first],(ll)x.second+y.second);
    }
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[j][i]);
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(dis[i][j]!=inf){
        grp[i].push_back({j,dis[i][j]});
        grp[j].push_back({i,dis[i][j]});
    }
    // n^3 logn
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)tdis[i][j]=inf,vis[j]=0;
        tdis[i][i]=0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        pq.push({0,i});
        while(pq.size()){
            auto frt=pq.top(); pq.pop();
            if(vis[frt.second])continue;
            vis[frt.second]=1;
            for(auto x:grp[frt.second])if(frt.first+x.second<tdis[i][x.first]){
                tdis[i][x.first]=frt.first+x.second;
                pq.push({tdis[i][x.first],x.first});
            }
        }
    }
    while(q--){
        int x,y; cin>>x>>y;
        ll ans=inf;
        for(auto a:edges[x])for(auto b:edges[y])ans=min(ans,tdis[a.first][b.first]+a.second+b.second);
        cout<<ans+wi[x]+wi[y]<<'\n';
    }
}
