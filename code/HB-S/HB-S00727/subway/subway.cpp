#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
using namespace std::chrono;
#define runt0 auto _t0=steady_clock::now();
#define seetime cerr<<"RunTime: "<<duration<double,micro>(steady_clock::now()-_t0).count()<<"ms\n"
#else
#define runt0
#define seetime
#endif
const int IO=1<<20;
const ll inf=2e18;
unsigned char buf[IO],*rp1,*rp2;
#define gc() (rp1==rp2&&(rp2=(rp1=buf)+fread(buf,1,IO,stdin))==rp1?EOF:*rp1++)
#define endl putchar('\n')
inline ll rd(){
    ll x=0;int c=gc();
    while(!isdigit(c)){
        c=gc();
    }
    while(isdigit(c)){
        x=x*10+(c^48);
        c=gc();
    }
    return x;
}
inline void wt(ll x){
    if(x>9){
        wt(x/10);
    }
    putchar((x%10)^48);
    return;
}
struct Node{
    int u,v;ll w;
    // bool operator<(const Node&A){return ww<A.ww;}
};
vector<Node> da;
namespace TaskA{
const int N=550,M=500050;
struct Edge{
    int nxt,to;ll w;
};
Edge e[M<<1];
int head[N+M],tot;
inline void addE(int u,int v,ll w){
    e[++tot]={head[u],v,w};
    head[u]=tot;
    return;
}
int n,m,d,Q;
ll w[M],dis[N+M];
int dep[N+M],fa[N+M][21];
void dfs(int u,int pre){
    dep[u]=dep[pre]+1;fa[u][0]=pre;
    for(int i=1;(1<<i)<=dep[u];i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==pre){
            continue;
        }
        dis[v]=dis[u]+e[i].w;
        dfs(v,u);
    }
    return;
}
int LCA(int x,int y){
    if(dep[x]<dep[y]){swap(x,y);}
    for(int i=20;i>=0;i--){
        if((1<<i)<=dep[x]-dep[y]){
            x=fa[x][i];
        }
    }
    if(x==y){return x;}
    for(int i=20;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];y=fa[y][i];
        }
    }
    return fa[x][0];
}

int aa[N+M];
int find(int x){ return(x==aa[x]?x:aa[x]=find(aa[x]));}
void Merge(int x,int y){
    x=find(x),y=find(y);
    if(x!=y){aa[y]=x;}
    return;
}
void Main(){
    n=rd(),m=rd(),d=rd(),Q=rd();
    for(int i=1;i<=m;i++){
        w[i]=rd();
    }
    da.reserve(m+n);
    for(int u=m+1;u<=m+n;u++){//Line m+1,m+n;
        int k=rd();
        for(int j=1;j<=k;j++){
            int v=rd();ll cst=rd();
            // addE(u,v,cst);addE(v,u,cst);
            da.emplace_back((Node){u,v,cst});
        }
    }
    sort(da.begin(),da.end(),[](const Node &A,const Node &B){return A.w<B.w;});
    for(auto &it:da){int u=it.u,v=it.v;
        if(find(u)==find(v)){
            continue;
        }ll cst=it.w;
        Merge(u,v);
        addE(u,v,cst);addE(v,u,cst);
    }
    dfs(1,0);
    while(Q--){
        int x=rd(),y=rd();
        ll ans=dis[x]+dis[y]-dis[LCA(x,y)]+w[x]+w[y];
        wt(ans);endl;
    }
    return;
}
}
namespace Task1_8{
const int N=250,M=400;
struct Edge{
    int nxt,to;ll w;
};
Edge e[M<<1];
int head[N+M],tot;
inline void addE(int u,int v,ll w){
    e[++tot]={head[u],v,w};
    head[u]=tot;
    return;
}
struct Vd{
    int v;ll d;
    bool operator<(const Vd &A)const {return d>A.d;}
};
priority_queue<Vd> pq;
int n,m,d,Q;
ll w[M],dis[N+M][N+M];
bool vis[M];
void dij(int s){
    if(vis[s]){return;}
    vis[s]=1;
    auto &dd=dis[s];
    for(int i=1;i<=n+m;i++){dd[i]=inf;}
    dd[s]=0;
    pq.push((Vd){s,0});
    while(!pq.empty()){
        Vd cur=pq.top();pq.pop();
        int u=cur.v;
        if(dd[u]<cur.d){continue;}
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;ll cst=e[i].w;
            if(dd[v]>dd[u]+cst){
                dd[v]=dd[u]+cst;
                pq.emplace((Vd){v,dd[v]});
            }
        }
    }
    return;
}

void Main(){
    n=rd(),m=rd(),d=rd(),Q=rd();
    for(int i=1;i<=m;i++){
        w[i]=rd();
    }
    for(int u=m+1;u<=m+n;u++){//Line m+1,m+n;
        int k=rd();
        for(int j=1;j<=k;j++){
            int v=rd();ll cst=rd();
            addE(u,v,cst);addE(v,u,cst);
        }
    }
    while(Q--){
        int x=rd(),y=rd();
        dij(x);
        wt(dis[x][y]+w[x]+w[y]);endl;
    }
    return;
}
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//duoceqingkong!
    runt0;
    int testid=rd();
    if((9<=testid&&testid<=19)){//tree_LCA 
        TaskA::Main();seetime;
        return 0;
    }
    if(0<=testid&&testid<=8){
        Task1_8::Main();seetime;
        return 0;
    }
    seetime;
    return 0;
}
/*
g++ "/home/user/Desktop/HB-S00727/subway8.cpp" -o T2 -O2 -std=c++14 -static -Wall -Wextra -Wshadow -DLOCAL
*/