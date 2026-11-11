#include <bits/stdc++.h>
using namespace std;
// char BEGIN;
const int N=1e6+5;
int cid;
int n,K;
vector<int> G[N];
pair<int,int> e[N];
int sp;
int deg[N],c[N],sz;
void co(int x,int y) {
    c[x]=1,++sz;
    for(int v:G[x]) if(v!=y) {
        co(v,x);
    } 
}
bool vis[N];
mt19937 rng(1031);
int rnd(int l,int r) {return rng()%(r-l+1)+l;}
const int ln=1e5+5;
int euler[18][ln*2],bg[ln],ed[ln],id,dep[ln];
int lca(int x,int y) {
    int l=min(bg[x],bg[y]),r=max(ed[x],ed[y]);
    int lg=__lg(r-l+1);
    return min(euler[lg][l],euler[lg][r-(1<<lg)+1],[](int x,int y) {return dep[x]<dep[y];});
}
int dis(int x,int y) {
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void dfs(int x,int y) {
    dep[x]=dep[y]+1;
    bg[x]=ed[x]=++id;
    euler[0][id]=x;
    for(int v:G[x]) if(v!=y) {
        dfs(v,x);
        ed[x]=++id;
        euler[0][id]=x;
    }
}
struct D {
    int x,y,len;
};
D merge(const D &a,const D &b) {
    if(!a.x && !b.x) return {0,0,0};
    if(!b.x) return a;
    if(!a.x) return b;
    int v1=dis(a.x,b.x);
    int v2=dis(a.x,b.y);
    int v3=dis(a.y,b.x);
    int v4=dis(a.y,b.y);
    int mx=max({a.len,b.len,v1,v2,v3,v4});
    if(a.len==mx) return a;
    if(b.len==mx) return b;
    if(v1==mx) return {a.x,b.x,v1};
    if(v2==mx) return {a.x,b.y,v2};
    if(v3==mx) return {a.y,b.x,v3};
    return {a.y,b.y,v4};
}
D s[ln];
void init(int x,int y ){
    s[x]={x,x,0};
    for(int v:G[x]) if(v!=y) {
        init(v,x);
        s[x]=merge(s[x],s[v]);
    } 
}
D pre[ln];
int ans;
void solve(int x,int y,D val) {
    val=merge(val,{x,x,0});
    D p={0,0,0};
    for(int v:G[x]) if(v!=y) {
        pre[v]=p;
        p=merge(p,s[v]);
    }
    for(int i=(int)G[x].size()-1;i>=0;--i) {
        int v=G[x][i];
        if(v==y) continue;
        D c=merge(val,pre[v]);
        ans=min(ans,max((s[v].len+1)/2,(c.len+1)/2));
        solve(v,x,c);
        val=merge(val,s[v]);
    }
}
void Main() {
    cin>>n>>K;
    for(int i=1;i<=n;++i) G[i].clear();
    for(int i=1;i<n;++i) {
        int u,v; cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        e[i]={u,v};
    }
    if(cid==11 || cid==12) {
        ans=1e9;
        id=0;
        dfs(1,0);
        for(int i=1;i<=__lg(id);++i) {
            for(int j=1;j<=id-(1<<i)+1;++j) {
                euler[i][j]=min(euler[i-1][j],euler[i-1][j+(1<<i-1)],[](int x,int y) {return dep[x]<dep[y];});
            }
        }
        init(1,0);
        solve(1,0,{0,0,0});
        cout<<ans<<'\n';
        return;
    }
    int ans=1e9;
    vector<int> A;
    if(n<=4000) for(int i=1;i<n;++i) A.push_back(i);
    else {
        if(cid==13 || cid==14) {
            int m=n/2;
            for(int i=m/2-3;i<=m/2+3;++i) A.push_back(i);
        }
        else {
            vector<int> f(n);
            for(int i=1;i<n;++i) f[i]=i,swap(f[i],f[rnd(1,i)]);
            for(int i=1;i<=min(n-1,(int)2e7/n);++i) A.push_back(f[i]);
        }
    }
    // int l=0,r=0;
    for(int _sp:A) {
        sp=_sp;
        auto [x,y]=e[sp];
        for(int i=1;i<=n;++i) deg[i]=G[i].size(),c[i]=0,vis[i]=0;
        deg[x]--,deg[y]--;
        sz=0;
        co(x,y);
        int L=sz,R=n-L;
        vector<int> q1,q2;
        for(int i=1;i<=n;++i) {
            if(deg[i]<=1) {
                if(c[i]) q1.push_back(i),vis[i]=1;
                else q2.push_back(i),vis[i]=1;
            }
        }
        int d=0;
        while(max(L,1)+max(R,1)>K) {
            ++d;
            vector<int> p1,p2;
            for(int i:q1) for(int v:G[i]) if(c[v] && !vis[v]) {
                if(--deg[v]<=1) p1.push_back(v),vis[v]=1;
            }
            for(int i:q2) for(int v:G[i]) if(!c[v] && !vis[v]) {
                if(--deg[v]<=1) p2.push_back(v),vis[v]=1;
            }
            L-=q1.size(),R-=q2.size();
            q1.swap(p1);
            q2.swap(p2);
        }
        // if(d<ans) l=L,r=R;
        ans=min(ans,d);
    } 
    // cerr<<l<<' '<<r<<'\n';
    cout<<ans<<'\n';
}
// char END;
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    // cerr<<(&END-&BEGIN)/1024.0/1024.0<<'\n';
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>cid;
    cin>>t;
    while(t--) Main();
}