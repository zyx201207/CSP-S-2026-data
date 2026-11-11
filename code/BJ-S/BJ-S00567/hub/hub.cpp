#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define i128 __int128
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace IO{
    template<typename T>
    inline void read(T &x){
        x=0;bool fl=1;
        char c=gc();
        while(c<'0'||c>'9'){if(c=='-')fl=0;c=gc();}
        while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=gc();
        x=fl?x:-x;
    }
    template<typename T>
    inline void write(T x){
        if(x<0) pc('-'),x=-x;
        if(x>9) write(x/10);
        pc(x%10+'0');
    }
}using namespace IO;
const int N=1e6+5;
int tid,T;
int n,k,ans;
vector<int>g[N];
bool vis[N],fl[N];
int d[N];
void df(int u,int dis,int fa){
    d[u]=min(d[u],dis);
    for(int v:g[u]){
        if(v==fa) continue;
        df(v,dis+1,u);
    }
}
void dfs(int u,int cnt,int c){
    if(cnt==2||c==k||u>n){
        rep(i,1,n) d[i]=1e9;
        // rep(i,1,n) if(fl[i]) cerr<<i<<' ';
        // cerr<<'\n';
        rep(i,1,n) if(fl[i]) df(i,0,0);
        int mx=0;
        rep(i,1,n) mx=max(mx,d[i]);
        // debug(mx);
        ans=min(ans,mx);
        return;
    }
    int cost=1;
    for(int v:g[u]) if(fl[v]) cost=0;
    fl[u]=1;
    dfs(u+1,cnt+cost,c+1);
    fl[u]=0;
    dfs(u+1,cnt,c);
}
inline void solve(){
    read(n),read(k);
    rep(i,1,n) g[i].clear(),fl[i]=0;
    ans=n;
    rep(i,1,n-1){
        int u,v;
        read(u),read(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if((k<=2&&n<=1000)||n<=10){
        dfs(1,0,0);
        write(ans),pc('\n');return;
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read(tid),read(T);
    while(T--) solve();
    return 0;
}