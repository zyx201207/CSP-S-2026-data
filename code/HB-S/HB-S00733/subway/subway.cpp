#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,ll>
#define pli pair<ll,int>
#define mkp make_pair
const int N=502,M=5e5+2;
ll w[M];
vector<pii> ve[M];
ll g[N][N];
vector<pii> G[N];
int c,n,m,d,q;
bool vis[N];
priority_queue<pli> pq;
ll dis[N][N];
void getdis(int u){
    for(int i=1; i<=n; i++) vis[i]=0,dis[u][i]=LLONG_MAX;
    dis[u][u]=0;
    while(!pq.empty()) pq.pop();pq.push({0,u});
    while(!pq.empty()){
        pii tp=pq.top();pq.pop();
        int x=tp.second;vis[x]=1;
        for(pii pi : G[x]){
            int y=pi.first;ll w=pi.second;
            if(dis[u][y]>dis[u][x]+w){
                dis[u][y]=dis[u][x]+w;
                if(!vis[y]) pq.push({dis[u][y],y});
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++) cin>>w[i];
    for(int i=1; i<=n; i++){
        int k;cin>>k;
        for(int j=1; j<=k; j++){
            int a,t;cin>>a>>t;
            ve[a].push_back(mkp(i,t));
        }
    }
    for(int i=1; i<=m; i++){
        int l=ve[i].size();
        for(int j=0; j<l; j++){
            int u=ve[i][j].first,w=ve[i][j].second;
            for(int k=j+1; k<l; k++){
                ll v=ve[i][k].first,x=ve[i][k].second;
                if(g[u][v]) g[u][v]=min(g[u][v],w+x);
                else g[u][v]=w+x;
                g[v][u]=g[u][v];
            }
        }
    }
    for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) if(g[i][j]){
        G[i].push_back(mkp(j,g[i][j]));
        G[j].push_back(mkp(i,g[i][j]));
    }
    for(int i=1; i<=n; i++) getdis(i);
    while(q--){
        int x,y;cin>>x>>y;
        int lx=ve[x].size(),ly=ve[y].size();
        ll ans=LLONG_MAX;
        for(int i=0; i<lx; i++){
            for(int j=0; j<ly; j++){
                int u=ve[x][i].first,v=ve[y][j].first;
                ans=min(ans,ve[x][i].second+ve[y][j].second+dis[u][v]);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
//15:10 100
//16:00 打了 T3 8pts -> 108
//16:06 好像会了/se
//16:39 初版代码完成！不会全源最短路所以写了 dij！通过了小样例！O(qd^2nlogn) 完了我忘记 dij 的复杂度了，也许是 nlog n？
//16:49 预处理一下最短路，变成 O(n^2log n+qd^2) 感觉很对！通过了所有大样例！！
//16:59 说实话有点慌，如果 dij 复杂度记错了的话就挂到 40pts 了 但是大样例跑得飞快啊
//17:07 检查了一遍，改了一个错，好慌啊啊啊啊
//17:13 上了个厕所。相信自己。去看 C 了/se
//18:26 摆了 应该是 100+100+16+10，不挂分都很难钩七了
//Ruri/xin
//freopen()
