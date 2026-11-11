#include <bits/stdc++.h>
using namespace std;using tp=long long;
#define For(i,l,r) for(tp i(l);i<=r;++i)
#define FoR(i,r,l) for(tp i(r);i>=l;--i)
inline tp read(){
    tp x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=='-'?f=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}inline bool write(tp x,char ch='\n'){return printf("%lld",x),putchar(ch),true;}
inline tp Max(tp x,tp y){return x>y?x:y;}
inline tp Min(tp x,tp y){return x<y?x:y;}
inline bool Cmax(tp&x,tp y){return x<y?x=y,true:false;}
inline bool Cmin(tp&x,tp y){return x>y?x=y,true:false;}
constexpr tp K=660;
constexpr tp N=1000100;
constexpr tp INF=4000000000000000000;
#define fr first
#define sd second
#define ep emplace
#define pb emplace_back
#define SIZ(G) tp(G.size())
using pt=pair<tp,tp>;
tp c,n,m,d,q,cnt;tp w[N],k[K],dis[N],ans[1010][1010];vector<tp>a[K],t[K];bool vis[N];
vector<pt>G[N];priority_queue<pt,vector<pt>,greater<pt>>Q;
inline void add(tp a,tp b,tp c){return G[a].pb(b,c),G[b].pb(a,c),void();}
inline void Dijkstra(tp s){
    For(i,1,cnt)dis[i]=INF,vis[i]=false;
    dis[s]=0;Q.ep(0,s);while(SIZ(Q)){
        tp u=Q.top().sd;Q.pop();
        if(vis[u])continue;vis[u]=true;
        for(auto to:G[u]){
            Cmin(dis[to.fr],dis[u]+to.sd)?Q.ep(dis[to.fr],to.fr),0:0;
        }
    }return void();
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();m=read();
    d=read();q=read();
    For(i,1,m)w[i]=read();cnt=m;
    For(i,1,n){k[i]=read();a[i].pb(0);t[i].pb(0);For(j,1,k[i])a[i].pb(read()),t[i].pb(read());}
    For(i,1,n){
        tp beg=cnt+1;++cnt;
        For(j,1,k[i])add(a[i][j],cnt,t[i][j]);
        // For(j,beg,cnt-1)add(j,j+1,0);
    }
    // cerr<<cnt<<' '<<q<<'\n';
    if(c<=11){
        For(i,1,m){
            Dijkstra(i);
            For(j,1,m)ans[i][j]=dis[j];
        }
        For(i,1,q){
            tp s=read(),t=read();
            write(ans[s][t]+w[s]+w[t]);
        }return 0;
    }
    For(i,1,q){
        tp s=read(),t=read();
        Dijkstra(s);write(dis[t]+w[s]+w[t]);
    }
    return 0;
}