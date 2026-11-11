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
#define ll long long
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
constexpr int N=1e6+5,INF=1e8;
struct{int u,v;} e[N];
int n,k,ans,d[N],len[N];
bool nopush[N];
vector<int> g[N];
int topo(int du,int dv){
    queue<int> q;
    int lst=n,res=0;
    rept(i,1,n){
        if(!nopush[i]&&d[i]==1){
            int other;
            for(int j:g[i]){
                if(i==du&&j==dv||i==dv&&j==du) continue;
                other=j;
            }
            if(d[other]==1){
                nopush[other]=true;
            }
            q.push(i);
            d[i]=0;
            len[i]=1,res=max(res,len[i]);
            --lst;
            if(lst==k) return res;
        }
    }
    while(q.size()){
        int u=q.front();q.pop();
        for(int v:g[u]){
            if(u==du&&v==dv||u==dv&&v==du||!d[v]) continue;
            --d[v];
            if(d[v]==1){
                q.push(v);
                d[v]=0;
                len[v]=len[u]+1,res=max(res,len[v]);
                --lst;
                if(lst==k) return res;
            }
        }
    }
    return INF;
}
void init(){
    rept(i,1,n){
        d[i]=g[i].size();
        nopush[i]=false;
    }
}
void solve(){
    cin>>n>>k;
    if(k==n){
        cout<<"0\n";
        return;
    }
    rept(i,1,n) g[i].clear();
    rep(i,0,n-1){
        cin>>e[i].u>>e[i].v;
        g[e[i].u].eb(e[i].v);
        g[e[i].v].eb(e[i].u);
    }
    init();
    ans=topo(-1,-1);
    rep(i,0,n-1){
        init();
        --d[e[i].u],--d[e[i].v];
        ans=min(ans,topo(e[i].u,e[i].v));
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,T;
    cin>>c>>T;
    while(T--) solve();
    return 0;
}