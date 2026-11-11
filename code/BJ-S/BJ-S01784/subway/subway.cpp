#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=505;
int c,n,m,d,qs,w[N],dis[M][M],bq[M][M];
vector<pair<int,int>>lines[N],g[M];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void dij(int s){
    memset(dis[s],0x3f,sizeof(dis[s]));
    dis[s][s]=0;
    q.push({0,s});
    while(!q.empty()){
        pair<int,int>f=q.top();
        q.pop();
        int d=f.first,nd=f.second;
        if(d>dis[s][nd])continue;
        for(pair<int,int>it:g[nd]){
            int v=it.first,w=it.second;
            if(dis[s][nd]+w<dis[s][v]){
                dis[s][v]=dis[s][nd]+w;
                q.push({dis[s][v],v});
            }
        }
    }
}signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>qs;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        while(k--){
            int x,y;
            cin>>x>>y;
            lines[x].push_back({i,y});
        }
    }memset(bq,0x3f,sizeof(bq));
    for(int i=1;i<=m;++i){
        int sz=lines[i].size();
        for(int j=0;j<sz;++j)for(int k=j+1;k<sz;++k){
            int l1=lines[i][j].first,l2=lines[i][k].first,mn=min(bq[l1][l2],lines[i][j].second+lines[i][k].second);
            bq[l1][l2]=bq[l2][l1]=mn;
        }
    }for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(bq[i][j])g[i].push_back({j,bq[i][j]});
    for(int i=1;i<=n;++i)dij(i);
    while(qs--){
        int u,v;
        cin>>u>>v;
        int ans=LLONG_MAX,szu=lines[u].size(),szv=lines[v].size();
        for(int i=0;i<szu;++i)for(int j=0;j<szv;++j)ans=min(ans,lines[u][i].second+lines[v][j].second+dis[lines[u][i].first][lines[v][j].first]);
        cout<<ans+w[u]+w[v]<<'\n';
    }return 0;
}