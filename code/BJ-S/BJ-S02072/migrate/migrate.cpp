#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define gc() getchar_unlocked()
int read(){
    int f=1,x=0,c=gc();
    while(!isdigit(c) and c!='-')c=gc();
    if(c=='-'){
        f=-1;
        c=gc();
    }
    do{
        x=(x<<1)+(x<<3)+(c^48);
        c=gc();
    }while(isdigit(c));
    return x*f;
}
const int N=2e6+5,M=305,inf=LLONG_MAX;
int c,t;
int n,d;
int x[N];
int l[N],r[N];
vector<int> e[N][2];
int to[N];
bool is[N];
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
void build(int x,int l,int r){
    if(l==r){
        to[l]=x;
        is[x]=1;
        return ;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    e[x][is[ls]].push_back(ls);
    e[x][is[rs]].push_back(rs);
    return ;
}
void mk(int x,int l,int r,int lt,int p){
    if(lt<=l and r<=p-1){
        e[to[p]][is[x]].push_back(x);
        return ;
    }
    if(lt<=mid)mk(ls,l,mid,lt,p);
    if(mid<p-1)mk(rs,mid+1,r,lt,p);
    return ;
}
int dst[N],cnt[N];
bool vis[N];
queue<int> q;
void dfs(int u,int x){
    for(int v:e[u][1]){
        if(!vis[v]){
            q.push(v);
            vis[v]=1;
            dst[v]=dst[x]+1;
            cnt[v]=cnt[x];
        }else if(dst[v]==dst[x]+1){
            cnt[v]+=cnt[x];
        }
    }
    for(int v:e[u][0]){
        dfs(v,x);
    }
    return ;
}
int bfs(int x){
    int res=0;
    for(int i=1;i<=n*4;i++){
        dst[i]=inf;
        cnt[i]=0;
        vis[i]=0;
    }
    dst[x]=0;
    cnt[x]=1;
    vis[x]=1;
    q.push(x);
    while(!q.empty()){
        int u=q.front();q.pop();
        res+=(cnt[u]==2);
        dfs(u,u);
    }
    return res;
}
namespace A{
    void solve(){
        int ans=0;
        n=read();
        d=read();
        for(int i=1;i<=n;i++){
            x[i]=read();
        }
        for(int i=1;i<=n;i++){
            l[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
        }
        for(int i=1;i<=n;i++){
            if(l[i]>1 and l[i]<=i-2 and l[l[i]+1]<l[l[i]+2]){
                ans++;
            }
        }
        cout<<ans<<'\n';
        return ;
    }
}
void solve(){
    int ans=0;
    n=read();
    d=read();
    for(int i=1;i<=n;i++){
        x[i]=read();
    }
    for(int i=1;i<=n*4;i++){
        e[i][0].clear();
        e[i][1].clear();
        is[i]=0;
    }
    for(int i=1;i<=n;i++){
        l[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
    }
    build(1,1,n);
    for(int i=1;i<=n;i++){
        if(l[i]<i)mk(1,1,n,l[i],i);
        ans+=bfs(to[i]);
    }
    cout<<ans<<'\n';
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    c=read();
    t=read();
    while(t--){
        if(11<=c){
            A::solve();
        }else{
            solve();
        }
    }
    return 0;
}   