#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
const int N=1000005,inf=1e9;
int n,k;
vector<int> Adj[N];
int dfn[N],dep[N],xu[N],LG[N<<1];

namespace LCA{
    int st[21][N*2];
    int ou[N*2];
    int in[N*2];

    void dfs(int x,int fa){
        ou[++ou[0]]=x;
        in[x]=ou[0];
        for(auto i:Adj[x]){
            if(i==fa) continue;
            dfs(i,x);
            ou[++ou[0]]=x;
        }
    }

    int lca(int u,int v){
        int L=in[u];
        int R=in[v];
        if(L>R) swap(L,R);
        int len=LG[R-L+1];
        int A=st[len][L];
        int B=st[len][R-(1<<len)+1];
        return (dep[ou[A]]>dep[ou[B]]?ou[B]:ou[A]);
    }

    void make(){
        memset(st,0,sizeof st);
        memset(ou,0,sizeof ou);
        dfs(1,0);
        _for(i,1,2*n) st[0][i]=i;
        //cout<<"ou[0]="<<ou[0]<<'\n';
        //_for(i,1,ou[0]) cout<<ou[i]<<' ';
        //cout<<'\n';
        _for(i,1,20){
            _for(j,1,2*n){
                if(j+(1<<i)-1 > 2*n) break;
                int A=st[i-1][j];
                int B=st[i-1][j+(1<<(i-1))];
                if(dep[ou[A]]<dep[ou[B]]) st[i][j]=A;
                else st[i][j]=B;
            }
        }
    }
}

void DFS(int x,int fa){
    if(x!=1) dep[x]=dep[fa]+1;
    dfn[x]=++dfn[0];
    xu[dfn[0]]=x;
    for(auto i:Adj[x]){
        if(i==fa) continue;
        DFS(i,x);
    }
}

void build(){
    DFS(1,0);
    LCA::make();
}

int f[N],g[N];
vector<int> node;

void dfs(int x,int fa,int mid){
    for(auto i:Adj[x]){
        if(i==fa) continue;
        dfs(i,x,mid);
        g[x]=max(g[i]+1,g[x]);
        f[x]=min(f[x],1+f[i]);
    }
    if(f[x]+g[x]<=mid){
        g[x]=-inf;
    }
    if(g[x]>=mid){
        f[x]=0;g[x]=-inf;
        node.push_back(x);
    }
    if((x==1&&g[x]>0)){
        f[x]=0;g[x]=-inf;
        node.push_back(x);
    }
}

bool cmp(int x,int y){
    return dfn[x]<dfn[y];
}

int dis(int u,int v){
    return dep[u]+dep[v]-2*dep[LCA::lca(u,v)];
}

int Get(vector<int> &v){
    if(v.size()==1) return 0;
    int sum=0;
    _for(i,0,v.size()-2){
        sum+=dis(v[i],v[i+1]);
    }
    return sum+dis(v[0],v.back());
}

bool divide(vector<int> &v){
    sort(v.begin(),v.end(),cmp);
    int sz=v.size();
    int sum=0;
    _for(i,0,sz-2){
        sum+=dis(v[i],v[i+1]);
    }
    if(sum+dis(v[0],v[sz-1])+2<=2*k) return 1;
    //for(auto i:v) cout<<i<<' ';
    //cout<<'\n';
    int mn=inf;
    _for(p,0,sz-2){
        int W=(sum+dis(v[p],v[0])-dis(v[p],v[p+1])+dis(v[p+1],v[sz-1]));
        if(W+4<=2*k) return 1;
    }
    sum+=dis(v[0],v[sz-1]);
    _for(p1,1,sz-2){
        _for(p2,p1,sz-2){
            int W=(sum+dis(v[p1],v[p2])+dis(v[p1-1],v[p2+1])-dis(v[p1-1],v[p1])-dis(v[p2],v[p2+1]));
            if(W+4<=2*k) return 1;
        }
    }
    return 0;
}

bool check(int mid){
    node.clear();
    _for(i,1,n) g[i]=0,f[i]=inf;
    dfs(1,0,mid);

    if(node.size()>k) return 0;
    if(node.size()<=2) return 1;
    if(node.size()<=k&&k<=2){
        return 1;
    }
    if(n==k) return 1;
    return divide(node);
}

void solve(){
    memset(dep,0,sizeof dep);
    memset(dfn,0,sizeof dfn);
    memset(xu,0,sizeof xu);
    _for(i,1,n) Adj[i].clear();
    cin>>n>>k;
    _for(i,2,n){
        int u,v; cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    build();
    int L=1,R=n,res=0;
    while(L<=R){
        int mid=L+R>>1;
        if(check(mid)) R=mid-1,res=mid;
        else L=mid+1;
    }
    cout<<res<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,T; cin>>c>>T;
    _for(i,1,2000000) LG[i]=__lg(i);
    while(T--){
        solve();
    }
    return 0;
}
