#include <bits/stdc++.h>
#include <cassert>
#define rept(i,a,b) for(int i(a);i<=(b);++i)
#define pert(i,a,b) for(int i(a);i>=(b);--i)
#define rep(i,a,b) for(int i(a);i<(b);++i)
#define per(i,a,b) for(int i(a);i>(b);--i)
#define ls(p) ((p)<<1)
#define rs(p) ((p)<<1|1)
#define lowbit(p) ((p)&-(p))
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
#define me(x,y) memset(x,y,sizeof(x))
#define int long long
#define ull unsigned long long
#define uint unsigned int
#define db double
#define ldb long double
#define pct __builtin_popcount
#define pctll __builtin_popcountll
#define clz __builtin_clz
#define clzll __builtin_clzll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
using namespace std;
constexpr int N=505,M=5e5+5,INF=1e18;
int c,n,m,d,q;
int dis[N][N];
int w[M];
vector<pii> g[M];
// w[i]：从i号地铁口到i号站厅的时间
// g[i]：存储从i号展厅可以到达的（线路，站厅到站台的时间）
inline void upd(int &x,int y){
    x=min(x,y);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    // 显然地铁口到站台的时间恒定，没用
    // 同一条线路的所有站台可以看成同一个点
    // 然后图变成了两层，第一层有5e5个，第二层有500个，第一层每个点度数<=20
    // 我们有时间在不同线路间跑O(n^3)全源最短路
    // 查询时暴力枚举第一条和最后一条线路
    rept(i,1,m) cin>>w[i];
    rept(i,1,n){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            g[a].eb(i,t);
        }
    }
    rept(i,1,n){
        rept(j,1,n){
            if(i!=j) dis[i][j]=INF;
        }
    }
    rept(i,1,m){
        rep(j,0,g[i].size()-1) rep(k,j+1,g[i].size()){
            pii up=g[i][j],vp=g[i][k];
            upd(dis[up.fi][vp.fi],up.se+vp.se);
            upd(dis[vp.fi][up.fi],up.se+vp.se);
        }
    }
    rept(k,1,n){
        rept(i,1,n){
            rept(j,1,n){
                upd(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v,ans=INF;
        cin>>u>>v;
        rep(i,0,g[u].size()){
            pii up=g[u][i];
            if(up.se>=ans) continue;
            rep(j,0,g[v].size()){
                pii vp=g[v][j];
                ans=min(ans,up.se+dis[up.fi][vp.fi]+vp.se);
            }
        }
        cout<<w[u]+w[v]+ans<<'\n';
    }
    return 0;
}