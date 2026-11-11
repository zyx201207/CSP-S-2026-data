#include<iostream>
#include<vector>
#include<utility>
constexpr int maxn=500+5,maxm=5e5+5;
int c,n,m,d,q;
long long dt[maxm];
long long dis[maxn][maxn];
std::vector<std::pair<int,int>>e[maxm];
long long ckmin(long long&x,long long v){if(x>v)x=v;return x;}
int main(){
    std::freopen("subway.in","r",stdin);
    std::freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) std::cin>>dt[i];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) dis[i][j]=1e18;
        dis[i][i]=0;
    }
    for(int i=1;i<=n;++i){
        int k;std::cin>>k;
        while(k--){
            int a,t;std::cin>>a>>t;
            e[a].emplace_back(i,t);
        }
    }
    for(int i=1;i<=m;++i){
        for(auto a:e[i]) for(auto b:e[i]) ckmin(dis[a.first][b.first],a.second+b.second);
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) ckmin(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--){
        int x,y;std::cin>>x>>y;long long ans=1e18;
        for(int i=0;i<(int)e[x].size();++i) for(int j=0;j<(int)e[y].size();++j) ckmin(ans,e[x][i].second+e[y][j].second+dis[e[x][i].first][e[y][j].first]);
        std::cout<<ans+dt[x]+dt[y]<<'\n';
    }
    return 0;
}