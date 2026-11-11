#include<bits/stdc++.h>
// #define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define us(n) (1ll<<(n))
#define si(V) (int)(V).size()
#define I(i,l,r) for(auto i=(l);i<(r);++i)
#define O(i,l,r) for(auto i=(l);i<=(r);++i)
#define U(i,r,l) for(auto i=(r);i>=(l);--i)
#define For(e,V) for(const auto &e:(V))
#define X(x) (cerr<<__LINE__<<": "<<#x<<" = "<<x<<endl)

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vl=vector<ll>;

template<typename T> T& omax(T &a,T b) { return a=max(a,b); }
template<typename T> T& omin(T &a,T b) { return a=min(a,b); }

bool bgM;

char gc() {
    static char buf[us(20)],*p1,*p2;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,us(20),stdin),p1==p2)?EOF:*p1++;
}
ll ri() {
    ll x=0; char c; bool f=0;
    while(c=gc(),!isdigit(c)) if(c=='-') f=1;
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=gc();
    return f?-x:x;
}
char rc() { char c; while(c=gc(),isspace(c)); return c; }

const int M=998244353;
struct mint {
    int x;
    constexpr mint():x(0) {}
    constexpr mint(ll v):x(0) { x=v%M; if(x<0) x+=M; }
    constexpr mint& operator+=(mint a) { if((x+=a.x)>=M) x-=M; return *this; }
    constexpr mint& operator-=(mint a) { if((x-=a.x)<0) x+=M; return *this; }
    constexpr mint& operator*=(mint a) { x=(ll)x*a.x%M; return *this; }
    constexpr friend mint operator+(mint a,mint b) { return a+=b; }
    constexpr friend mint operator-(mint a,mint b) { return a-=b; }
    constexpr friend mint operator*(mint a,mint b) { return a*=b; }
    constexpr friend mint Pow(mint a,ll b) { mint x=1; for(;b;b>>=1,a*=a) if(b&1) x*=a; return x; }
    constexpr friend mint Inv(mint a) { return Pow(a,M-2); }
    friend ostream& operator<<(ostream &o,mint a) { return o<<a.x; }
} ;

const int inf=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3f;

namespace _ {
int testid;
int n,K;
const int Mn=1e6+10;
vi G[Mn];
int fa[Mn];
pii ddfs(int u,int F) {
    pii x={0,u}; fa[u]=F;
    For(v,G[u]) if(v!=F) {
        auto t=ddfs(v,u);
        t.fi++; omax(x,t);
    }
    return x;
}
int rt1,rt2;
int dep[Mn],md[Mn],sc[Mn];
void pdfs(int u,int F) {
    md[u]=dep[u]; sc[u]=-inf; fa[u]=F;
    For(v,G[u]) if(v!=F) {
        dep[v]=dep[u]+1;
        pdfs(v,u);
        if(md[v]>md[u]) {
            sc[u]=md[u]; md[u]=md[v];
        } else if(md[v]>sc[u]) {
            sc[u]=md[v];
        }
    }
}
int L;
int f[Mn],g[Mn],h[Mn];
vector<int> V;
void dfs(int u,int F) {
    f[u]=1;
    if(md[u]==dep[u]) g[u]=0;
    For(v,G[u]) if(v!=F) dfs(v,u);
    int now=1;
    For(v,G[u]) if(v!=F) {
        int w=md[v]-dep[u]>L?f[v]:0;
        now=min(now+w,f[u]+h[v]);
        f[u]+=w;
    }
    omin(h[u],now);
    omin(h[u],f[u]);
    omin(g[u],f[u]);
    omin(h[u],g[u]);
    for(int v=u;dep[v]!=1;v=fa[v]) {
        int t=md[fa[v]]==md[v]?sc[fa[v]]:md[fa[v]];
        if(t-dep[fa[v]]+dep[u]-dep[fa[v]]>L) break;
        omin(g[fa[v]],f[u]);
        if(dep[fa[v]]==1) V.pb(u);
    }
    if(dep[u]==1) V.pb(u);
    for(int v=u,now=-inf;dep[v]!=1;v=fa[v]) {
        now=max(now,md[fa[v]]==md[v]?sc[fa[v]]:md[fa[v]]);
        if(now-dep[fa[v]]>L) break;
        omin(h[fa[v]],g[u]+1);
    }
}
int mn;
void cdfs(int u,int F,int w) {
    omin(mn,g[u]);
    For(v,G[u]) if(v!=F) {
        int t=md[fa[v]]==md[v]?sc[fa[v]]:md[fa[v]];
        if(t-1+w<=L) {
            cdfs(v,u,w);
        }
    }
}
bool chk() {
    O(i,1,n) f[i]=g[i]=h[i]=inf;
    V.clear(); 
    dfs(rt1,rt2);
    auto V1=V; V.clear();
    dfs(rt2,rt1);
    auto V2=V; V.clear();
    if(min(h[rt1]+f[rt2],f[rt1]+h[rt2])<=K) return 1;
    For(e,V1) {
        mn=inf;
        cdfs(rt2,rt1,dep[e]);
        if(mn+f[e]<=K) return 1;
    }
    For(e,V2) {
        mn=inf;
        cdfs(rt1,rt2,dep[e]);
        if(mn+f[e]<=K) return 1;
    }
    return 0;
}

void _() {
    n=ri(); K=ri();
    O(i,1,n) G[i].clear();
    // 清空
    O(i,1,n-1) {
        int u=ri(),v=ri();
        G[u].pb(v); G[v].pb(u);
    }
    int x=ddfs(1,0).se;
    auto t=ddfs(x,0); int y=t.se;
    O(i,1,(t.fi-1)/2) y=fa[y];
    rt1=y; rt2=fa[y];
    dep[rt1]=1; pdfs(rt1,rt2);
    dep[rt2]=1; pdfs(rt2,rt1);
    int res=0;
    // L=6; cerr<<chk()<<endl;
    for(int l=0,r=n,mid;l<=r;) {
        L=mid=l+r>>1;
        (chk())?(res=mid,r=mid-1):(l=mid+1);
    }
    cout<<res<<endl;
}

void _start() {

}

}

bool edM;

signed main() {
    // freopen("in.txt","r",stdin);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    // cerr<<"Memory: "<<fabs(&bgM-&edM)/1024/1024<<"MB"<<endl;
    _::testid=ri();
    int T=ri();
    _::_start();
    O(i,1,T) {
        _::_();
    }
    // cerr<<"Time: "<<(double)clock()<<"ms"<<endl;
    return 0;
}

/*
g++ hub.cpp -o a -std=c++14 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC "-Wl,--stack=1000000000" -Wall -Wextra && a <in.txt >out.txt 2>err.txt
g++ hub.cpp -o a -std=c++14 -O2 -Wall -Wextra "-Wl,--stack=1000000000" && a <in.txt >out.txt 2>err.txt
*/