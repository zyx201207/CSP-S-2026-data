#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define f(i,j,n) for(int i=(j);i<=(n);i++)
#define F(i,n,j) for(int i=(n);i>=(j);i--)
#define updmin(a,b) a=min(a,b)
#define updmax(a,b) a=max(a,b)
#define updsum(a,b) a=(a+(b))%mod
#define pri_grt(x) x,vector<x>,greater<x>
#define arr(x) array<int,x>
#define arrl(x) array<ll,x>
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
namespace fsd{
    #define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MX,stdin)),p1==p2?EOF:*p1++)
    const int MX=1<<20;
    char buf[MX],*p1,*p2;
    inline int read(){
        int ak=0,csp=1;
        char c=gc();
        while(!isdigit(c)){if(c=='-')csp=-1;c=gc();}
        while(isdigit(c))ak=ak*10+(c-'0'),c=gc();
        return ak*csp;
    }
}
using fsd::read;
#define NXD
const int N=1e6+10;
const int inf=LLONG_MAX/2;
int n,K;
vector<int> h[N];
int umaxd[N],maxd[N];
int dep[N],fa[N],root;
bool on[N];
vector<int> C;
arr(2) mx;
void dfsf(int k,int prt,int dpe){
    mx=max(mx,arr(2){dpe,k});
    for(auto v:h[k])if(v!=prt)dfsf(v,k,dpe+1);
}
void dfsi(int k,int prt,int dpe=0){
    maxd[k]=0,dep[k]=dpe,fa[k]=prt;
    for(auto v:h[k])if(v!=prt){
        dfsi(v,k,dpe+1);
        updmax(maxd[k],maxd[v]+1);
    }
}
void dfsmk(int k,int prt){
    on[k]=1,C.pb(k);
    for(auto v:h[k])if(v!=prt&&maxd[v]+1==maxd[k]){dfsmk(v,k);return;}
}
void dfsx(int k,int prt){
    int s=umaxd[k];
    for(auto v:h[k])if(v!=prt)updmax(umaxd[v],s+1),updmax(s,maxd[v]+1);
    s=0;
    F(j,(int)h[k].size()-1,0){int v=h[k][j];if(v!=prt)updmax(umaxd[v],s+1),updmax(s,maxd[v]+1);}
    for(auto v:h[k])if(v!=prt)dfsx(v,k);
}
int dp[N];
void dfs(int k,int prt,int T){
    dp[k]=1;
    for(auto v:h[k])if(v!=prt){
        dfs(v,k,T);
        if(maxd[v]>=T)dp[k]+=dp[v];
    }
}
int up[N];
vector<arr(2)> V[N];
void dfs2(int k,int prt,int rt,int T){
    if(up[k]<=T&&!on[k])V[rt].pb({dep[k],dp[k]});
    int s=up[k];
    for(auto v:h[k])if(!on[v]&&v!=prt)updmax(up[v],s+1),updmax(s,maxd[v]+1);
    s=0;
    F(j,(int)h[k].size()-1,0){int v=h[k][j];if(!on[v]&&v!=prt)updmax(up[v],s+1),updmax(s,maxd[v]+1),dfs2(v,k,rt,T);}
}
int pre[N],suf[N];
struct Mst{
    struct abc{
        int lx,rx;
        int minn;
        bool tg;
    }Tree[N*4];
#define lx(k) Tree[k].lx
#define rx(k) Tree[k].rx
#define mid ((l+r)>>1)
    int cnt=0;
    void build(int &k,int l,int r){
        Tree[k=++cnt]={0,0,inf,0};
        if(l==r)return;
        build(lx(k),l,mid),build(rx(k),mid+1,r);
    }
    void modify(int k,int p,int v,int l,int r){
        // if(l==r)cout<<"modify "<<p<<" "<<v<<endl;
        updmin(Tree[k].minn,v);
        if(l==r)return;
        pushdown(k);
        if(p<=mid)modify(lx(k),p,v,l,mid);
        else modify(rx(k),p,v,mid+1,r);
    }
    void upd(int k){Tree[k].tg=1,Tree[k].minn=inf;}
    void pushdown(int k){if(Tree[k].tg)upd(lx(k)),upd(rx(k)),Tree[k].tg=0;}
    void pushup(int k){Tree[k].minn=min(Tree[lx(k)].minn,Tree[rx(k)].minn);}
    void re(int k,int L,int R,int l,int r){
        if(L>R)return;
        if(L<=l&&r<=R)return upd(k);
        pushdown(k);
        if(L<=mid)re(lx(k),L,R,l,mid);
        if(R>mid)re(rx(k),L,R,mid+1,r);
        pushup(k);
    }
#undef mid
}_mst;
bool check(int T){
    // cout<<"=================check "<<T<<"=================\n";
    f(i,0,n)up[i]=0,V[i].clear();
    dfs(root,0,T);
    // f(i,1,n)cout<<dp[i]<<" ";cout<<endl;
    f(k,1,n)if(dp[k]<=K&&umaxd[k]<=T)return 1;
    // cout<<"??\n";
    for(auto v:C)dfs2(v,0,v,T);
    // cout<<"??\n";
    _mst.cnt=0,_mst.build(*(new int),-n,n);
    int uv=0;
    auto re=[&](int L,int R){updmax(L,-n),updmin(R,n);if(L<=R)_mst.re(1,L,R,-n,n);};
    f(i,0,(int)C.size()-1){
        if(umaxd[C[i]]<=T)uv=0;
        uv++;
        for(auto v:h[C[i]])if(!on[v]&&maxd[v]>=T)uv+=dp[v];
        if(uv<=K&&(int)C.size()-i-1<=T)return 1;
        // cout<<i<<" "<<uv<<endl;
        _mst.modify(1,-i,uv,-n,n);
        for(auto v:h[C[i]])if(!on[v])re(T-(i+maxd[v]+1)+1,n);
        re(T-i+1,n);
        for(auto [v,p]:V[C[i]])if(v<=T)_mst.modify(1,v-2*i,p,-n,n);
        // cout<<":"<<i<<" "<<_mst.Tree[1].minn<<endl;
        pre[i]=_mst.Tree[1].minn;
    }
    _mst.cnt=0,_mst.build(*(new int),-n,n);
    F(i,(int)C.size()-1,0){
        // cout<<"++"<<i<<" "<<dp[C[i]]<<endl;
        _mst.modify(1,i,dp[C[i]],-n,n);
        for(auto v:h[C[i]])if(!on[v])re(T-(-i+maxd[v]+1)+1,n);
        re(T+i+1,n);
        for(auto [v,p]:V[C[i]])if(v-2*i+(int)C.size()-1<=T)_mst.modify(1,v,p,-n,n);
        // cout<<"-->"<<i<<" "<<_mst.Tree[1].minn<<endl;
        suf[i]=_mst.Tree[1].minn;
    }
    f(i,1,(int)C.size()-1)if(pre[i-1]+suf[i]<=K)return 1;
    return 0;
}
void gs(){
    n=read(),K=read();
    f(i,1,n)h[i].clear(),on[i]=0,umaxd[i]=0;
    C.clear();
    f(i,1,n-1){
        int p=read(),q=read();
        h[p].pb(q),h[q].pb(p);
    }
    mx={0,0};
    dfsf(1,0,1);
    root=mx[1];
    dfsi(root,0),dfsx(root,0),dfsmk(root,0);
    // for(auto v:C)cout<<v<<" ";cout<<endl;
    // f(i,1,n)cout<<umaxd[i]<<" ";cout<<endl;
    int l=0,r=n,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%lld\n",ans);
}
// #define XQZ
signed main(){
#ifndef XQZ
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
#endif
#ifdef NXD
    int c=0,t=0;cin>>c>>t;while(t--)
#endif
    gs();
    return 0;
}