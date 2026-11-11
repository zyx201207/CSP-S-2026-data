#include<bits/stdc++.h>
// #define int long long
#define rep(i,n) for(int i=1;i<=(n);++i)
#define lop(i,n) for(int i=(n);i;--i)
#define hh(i,a,b) for(int i=a;i<=b;++i)
#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define pii pair<int,int>
#define X first
#define Y second
#define prq priority_queue
#define eb emplace_back
#define pb push_back
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
double Time(){
    return 1.*clock()/CLOCKS_PER_SEC;
}
void cmax(int&a,int b){
    if(a<b)a=b;
}
void cmin(int&a,int b){
    if(a>b)a=b;
}
const int N=4000+7;//,INF_LL=1e18;
int D,n,k,fa[N],mx[N],gg[N];
vector<int>G[N];
int lc,rc;
void dfs(int u){
    mx[u]=0;gg[u]=0;//d[u]=d[fa[u]]+1;
    for(int v:G[u]){
        if(v==fa[u])continue;
        fa[v]=u;
        dfs(v);
        mx[u]=max(mx[v]+1,mx[u]);
        gg[u]+=gg[v];
        // if(d[cov[u]]>d[cov[v]])cov[u]=cov[v];
    }
    if(gg[u])++gg[u];
    if(!gg[u]&&mx[u]==D)gg[u]=1;
}
int gsd,kkk;
void dfs(int u,int nmx){
    if(nmx>D)return;
    int xx=-2,yy=-2,xid=0;
    for(int v:G[u]){
        if(v==fa[u])continue;
        if(v==gsd)continue;
        if(xx<mx[v])yy=xx,xx=mx[v],xid=v;
        else if(yy<mx[v])yy=mx[v];
    }
    for(int v:G[u]){
        if(v==fa[u])continue;
        if(v==gsd)continue;
        dfs(v,max(nmx,(v==xid?yy:xx)+1)+1);
    }
    if(!kkk)
    cmin(lc,gg[u]);
    else cmin(rc,gg[u]);
}
bool check(int mid){
    D=mid;
    rep(root,n){
        // if(root!=3)continue;
        fa[root]=0;
        dfs(root);
        if(gg[root]<=k)return 1;
        // cerr<<gg[2]<<" "<<gg[4]<<"\n";
        for(int krc:G[root]){
            // cerr<<krc<<"\n";
            gsd=krc;
            kkk=0;
            lc=rc=n;
            dfs(root,0);
            kkk=1;
            dfs(krc,0);
            if(lc+rc<=k)return 1;
            // cerr<<lc<<' '<<rc<<"\n";
        }
    }
    // cerr<<"%\n";
    return 0;
}
int solve(){
    cin>>n>>k;
    rep(i,n)G[i].clear();
    // cerr<<"?\n";
    rep(i,n-1){
        int u,v;cin>>u>>v;
        G[u].pb(v);G[v].pb(u);
    }
    if(k==n){
        cout<<"0\n";
        return 0;
    }
    // check(1);
    int l=1,r=n-1,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<'\n';
    return 0;
}
main(){
    FILE("hub");
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _,T=1;
    cin>>_>>T;
    // T=1;
    while(T--)solve();
    // cerr << Time() << "\n";
    return 0;
}