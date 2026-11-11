#define pc putchar
#define gc getchar
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll read(){
    ll x=0;int f=1;char ch=gc();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=gc();}
    while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
    return x*f;
}
void write(ll x){
    if(x<0) pc('-'),x=-x;
    if(x>=10) write(x/10);
    pc(x%10+'0');
}
#define int ll
#define pii pair<int,int>
#define fi first
#define se second
const int N=502,M=5e5+2,M1=1002,Q=1e5+2;
int c,n,m,d,q,w[M];
namespace to11{
    int dis[M1][M1];
    vector<pii>e[M1+N];
    void add(int u,int v,int w){
        e[u].push_back({v,w});e[v].push_back({u,w});
    }
    void dijstra(int s){
        priority_queue<pii>q;
        memset(dis[s],0x7f,sizeof dis[s]);
        dis[s][s]=0;
        q.push({0,s});
        while(!q.empty()){
            pii k=q.top();q.pop();
            int u=k.se,d=-k.fi;
            if(d>dis[s][u]) continue;
            for(pii tmp:e[u]){
                int v=tmp.fi,w=tmp.se;
                if(d+w<dis[s][v]){
                    dis[s][v]=d+w;
                    q.push({-d-w,v});
                }
            }
        }
    }
    void sol(){
        for(int i=1;i<=n;i++){
            int cnt=read();
            for(int j=1;j<=cnt;j++){
                int x=read(),t=read();
                add(x,m+i,t),add(m+i,x,t);
            }
        }
        for(int i=1;i<=m;i++) dijstra(i);
        for(int i=1;i<=q;i++){
            int x=read(),y=read();
            write(dis[x][y]+w[x]+w[y]),pc('\n');
        }
    }
};
vector<pii>e[M+N];
int dis[N+M];
void add(int u,int v,int w){
    e[u].push_back({v,w});
}
struct query{
    int x,y,ans;
}qu[Q];
void dij(int s){
    memset(dis,0x7f,sizeof dis);
    dis[s]=0;
    priority_queue<pii>q;q.push({0,s});
    while(!q.empty()){
        pii k=q.top();q.pop();
        int u=k.se,d=-k.fi;
        if(dis[u]<d) continue;
        for(pii tmp:e[u]){
            int v=tmp.fi,w=tmp.se;
            if(d+w<dis[v]){
                dis[v]=d+w;
                q.push({-dis[v],v});
            }
        }
    }
}
void dij1(int s){
    memset(dis,0x7f,sizeof dis);
    dis[s]=0;
    queue<pii>q;q.push({0,s});
    while(!q.empty()){
        pii k=q.front();q.pop();
        int u=k.se,d=k.fi;
        if(dis[u]<d) continue;
        for(pii tmp:e[u]){
            int v=tmp.fi,w=tmp.se;
            if(d+w<dis[v]){
                dis[v]=d+w;
                q.push({dis[v],v});
            }
        }
    }
}
void solve(){
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    if(m<=1000){
        to11::sol();
        return;
    }
    int T=0;
    for(int i=1;i<=n;i++){
        int cnt=read();
        for(int j=1;j<=cnt;j++){
            int a=read(),t=read();
            T=t;
            if(c>19) add(a,i+m,t),add(i+m,a,t);
            else add(a,i+m,1),add(i+m,a,1);
        }
    }
    for(int i=1;i<=q;i++) qu[i].x=read(),qu[i].y=read(),qu[i].ans=1e18+7;
    for(int i=1;i<=n;i++){
        if(c>19) dij(m+i);
        else dij1(m+i);
        for(int i=1;i<=q;i++) qu[i].ans=min(qu[i].ans,dis[qu[i].x]+dis[qu[i].y]);
    }
    for(int i=1;i<=q;i++){
        if(c>19) write(w[qu[i].x]+w[qu[i].y]+qu[i].ans),pc('\n');
        else write(w[qu[i].x]+w[qu[i].y]+T*qu[i].ans),pc('\n');
    }
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int __=1;
    while(__--) solve();
    return 0;
}
//I only have 208pts;
//shen mi T2,wo you yi ban shi jian mei you cheng gong li jie ti yi
//hai de wo T4 mei da
