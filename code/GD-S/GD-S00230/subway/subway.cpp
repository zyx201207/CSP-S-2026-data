#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long LL;

LL meiyongdedongxi,n,m,d,q;
LL www[500010];
vector<pair<LL,LL>> bh[500010];
LL dis[510][510];
    // bool vis[510];

void add(LL u,LL v,LL w){
        // vis[u]=vis[v]=true;
    dis[u][v]=min(dis[u][v],w);
    dis[v][u]=min(dis[v][u],w);
}

void floyd(){
    for(LL k=1;k<=n;k++){
        for(LL i=1;i<=n;i++){
            for(LL j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dis,0x3f,sizeof(dis));
    cin>>meiyongdedongxi>>n>>m>>d>>q;
    for(LL i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(LL i=1;i<=m;i++){
        cin>>www[i];
    }
    for(LL i=1;i<=n;i++){
        LL k;
        cin>>k;
        for(LL j=1;j<=k;j++){
            LL a,t;
            cin>>a>>t;
            bh[a].push_back({i,t});
        }
    }
    // cerr<<bh[118].size()<<'\n';
    for(LL i=1;i<=m;i++){
        for(LL j=0;j<bh[i].size();j++){
            for(LL k=0;k<j;k++){
                add(bh[i][j].first,bh[i][k].first,bh[i][j].second+bh[i][k].second);
            }
        }
    }
        // for(int i=1;i<=n;i++){
        //     if(!vis[i]){
        //         cerr<<i<<'\n';
        //     }
        // }
    floyd();
    for(LL i=1;i<=q;i++){
        LL u,v;
        cin>>u>>v;
        LL sum=www[u]+www[v];
        LL ans=0x3f3f3f3f3f3f3f3f;
        for(pair<LL,LL> j:bh[u]){
            for(pair<LL,LL> k:bh[v]){
                // if(j.first==k.first){
                //     cerr<<dis[j.first][k.first]<<' '<<j.second<<' '<<k.second<<'\n';
                // }
                ans=min(ans,dis[j.first][k.first]+j.second+k.second);
            }
        }
        cout<<ans+sum<<'\n';
    }
    return 0;
}