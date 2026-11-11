#include <bits/stdc++.h>
using namespace std;
#define int long long
const int S=5e5+5;
int w[S];
int bel[S][25],t[S][25],cnt[S];
const int N=505;
int f[N][N];
vector<pair<int,int> > g[N];
bitset<505> vis;
int dis[N][N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> > pq;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdin);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(f,0x1f,sizeof f);
    int no=f[0][0];
    for(int i=1;i<=n;++i)f[i][i]=0;
    //the rushing of metro doesn't cost any time? rediculous!
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int id=1;id<=k;++id){
            int x;
            int y;
            cin>>x>>y;
            bel[x][cnt[x]]=i;
            t[x][cnt[x]++]=y;
        }
    }
    for(int i=1;i<=m;++i){
        for(int id1=0;id1<cnt[i];++id1)for(int id2=0;id2<id1;++id2){
            int a1=bel[i][id1],a2=bel[i][id2];
            int t1=t[i][id1],t2=t[i][id2];
            f[a1][a2]=min(f[a1][a2],t1+t2);
            f[a2][a1]=min(f[a2][a1],t1+t2);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if((i!=j)&&(f[i][j]<no/2))g[i].emplace_back(make_pair(j,f[i][j]));
            //cout<<"f["<<i<<"]["<<j<<"]="<<f[i][j]<<'\n';
        }
    }
    memset(dis,0x1f,sizeof dis);
    for(int i=1;i<=n;++i){
        vis.reset();
        dis[i][i]=0;
        pq.push(make_pair(0,i));
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            if(vis.test(u))continue;
            vis.set(u);
            for(auto p:g[u]){
                int v=p.first;
                int w=p.second;
                if(vis[v])continue;
                if(dis[i][v]>dis[i][u]+w){
                    dis[i][v]=dis[i][u]+w;
                    pq.push(make_pair(dis[i][v],v));
                }
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        int ans=no;
        for(int idu=0;idu<cnt[u];++idu)for(int idv=0;idv<cnt[v];++idv){
            ans=min(ans,dis[bel[u][idu]][bel[v][idv]]+t[u][idu]+t[v][idv]);
        }
        cout<<(ans>=no/2?-1:ans+w[u]+w[v])<<'\n';
    }
    return 0;
}