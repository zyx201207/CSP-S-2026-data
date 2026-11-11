// g++ subway.cpp -o subway -O2 -std=c++14 -static

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#define pii pair<ll,ll>
#define x first
#define y second
#define gc getchar_unlocked
using namespace std;
typedef long long ll;
const ll N=505,M=5e+5+5,Q=1e+5+5,D=25;
inline ll read(){
    ll x=0;char c=gc();
    while(c<'0'||c>'9')c=gc();
    while(c>='0'&&c<='9')
    x=x*10+c-'0',c=gc();
    return x;
}
ll c,n,m,d,q;
ll w[M],k[N];
vector<ll> a[N],t[N];
struct Edge{
    ll v,w,nxt;
}e[M*4];
ll hed[M*4],ncnt=1,ecnt=1;
inline void addEdge(ll u,ll v,ll w){
    e[ecnt].v=v;
    e[ecnt].w=w;
    e[ecnt].nxt=hed[u];
    hed[u]=ecnt++;
}
ll dis_[N][N];
int main(void){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    c=read();n=read();m=read();d=read();q=read();
    ncnt=n+1;
    for(ll i=1;i<=m;i++)w[i]=read();
    for(ll i=1;i<=n;i++){
        k[i]=read();
        a[i].resize(k[i]+5);
        t[i].resize(k[i]+5);
        for(ll j=1;j<=k[i];j++){
            a[i][j]=read();
            t[i][j]=read();
            addEdge(m+i,a[i][j],t[i][j]);
            addEdge(a[i][j],m+i,t[i][j]);
        }
    }
    memset(dis_,0x3f,sizeof(dis_));
    for(ll i=1;i<=n;i++){// O(md)
        for(ll j=hed[m+i];j;j=e[j].nxt){
            for(ll k=hed[e[j].v];k;k=e[k].nxt){
                if(m+i==e[k].v)continue;
                dis_[i][e[k].v-m]=min(dis_[i][e[k].v-m],e[j].w+e[k].w);
            }
        }
    }
    for(ll i=1;i<=n;i++)
        dis_[i][i]=0;
    for(ll k=1;k<=n;k++)
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                dis_[i][j]=min(dis_[i][j],dis_[i][k]+dis_[k][j]);
    pii uu[D],vv[D];
    ll ucnt,vcnt;
    while(q--){
        ll u,v;
        ll ans=1e+18;
        u=read();v=read();
        ucnt=0;vcnt=0;
        for(ll i=hed[u];i;i=e[i].nxt)
            uu[++ucnt]=pii(e[i].v,e[i].w);
        for(ll i=hed[v];i;i=e[i].nxt)
            vv[++vcnt]=pii(e[i].v,e[i].w);
        for(ll i=1;i<=ucnt;i++)
            for(ll j=1;j<=vcnt;j++)
                ans=min(ans,uu[i].y+vv[j].y+dis_[uu[i].x-m][vv[j].x-m]);
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}

/*

// g++ subway.cpp -o subway -O2 -std=c++14 -static

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#define pii pair<int,int>
#define x first
#define y second
#define gc getchar_unlocked
using namespace std;
typedef long long ll;
const int N=505,M=5e+5+5,Q=1e+5+5;
inline int read(){
    int x=0;char c=gc();
    while(c<'0'||c>'9')c=gc();
    while(c>='0'&&c<='9')
    x=x*10+c-'0',c=gc();
    return x;
}
int c,n,m,d,q;
int w[M],k[N];
vector<int> a[N],t[N];
struct Edge{
    int v,w,nxt;
}e[M*4];
int hed[M*4],ncnt=1,ecnt=1;
inline void addEdge(int u,int v,int w){
    e[ecnt].v=v;
    e[ecnt].w=w;
    e[ecnt].nxt=hed[u];
    hed[u]=ecnt++;
}
int dis[N+M];
bool vis[N+M];
void dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<pii,vector<pii>,greater<pii> >q;
    dis[s]=0;
    q.push(pii(0,s));
    while(!q.empty()){
        int u=q.top().y,d=q.top().x;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=hed[u];i;i=e[i].nxt)
            if(!vis[e[i].v]&&d+e[i].w<dis[e[i].v])
                dis[e[i].v]=d+e[i].w,q.push(pii(d+e[i].w,e[i].v));
    }
    // for(int i=1;i<=n+m;i++)
    //     cout<<dis[i]<<' ';
    
}
int ans[Q];
vector<pii> tsk[M];
int main(void){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    c=read();n=read();m=read();d=read();q=read();
    ncnt=n+1;
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        k[i]=read();
        a[i].resize(k[i]+5);
        t[i].resize(k[i]+5);
        for(int j=1;j<=k[i];j++){
            a[i][j]=read();
            t[i][j]=read();
            addEdge(m+i,a[i][j],t[i][j]);
            addEdge(a[i][j],m+i,t[i][j]);
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        u=read();v=read();
        tsk[u].push_back(pii(v,i));
    }
    for(int i=1;i<=m;i++){
        if(tsk[i].empty())continue;
        dijkstra(i);
        for(int j=0;j<tsk[i].size();j++)
            ans[tsk[i][j].y]=w[i]+w[tsk[i][j].x]+dis[tsk[i][j].x];
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<'\n';
    return 0;
}

*/

/*

// g++ subway.cpp -o subway -O2 -std=c++14 -static

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#define pii pair<ll,ll>
#define x first
#define y second
#define gc getchar_unlocked
using namespace std;
typedef long long ll;
const ll N=505,M=5e+5+5,Q=1e+5+5,D=25;
inline ll read(){
    ll x=0;char c=gc();
    while(c<'0'||c>'9')c=gc();
    while(c>='0'&&c<='9')
    x=x*10+c-'0',c=gc();
    return x;
}
ll c,n,m,d,q;
ll w[M],k[N];
vector<ll> a[N],t[N];
struct Edge{
    ll v,w,nxt;
}e[M*4];
ll hed[M*4],ncnt=1,ecnt=1;
inline void addEdge(ll u,ll v,ll w){
    e[ecnt].v=v;
    e[ecnt].w=w;
    e[ecnt].nxt=hed[u];
    hed[u]=ecnt++;
}
// ll dis[N+M];
// bool vis[N+M];
// void dijkstra(ll s){
//     memset(dis,0x3f,sizeof(dis));
//     memset(vis,0,sizeof(vis));
//     priority_queue<pii,vector<pii>,greater<pii> >q;
//     dis[s]=0;
//     q.push(pii(0,s));
//     while(!q.empty()){
//         ll u=q.top().y,d=q.top().x;
//         q.pop();
//         if(vis[u])continue;
//         vis[u]=1;
//         for(ll i=hed[u];i;i=e[i].nxt)
//             if(!vis[e[i].v]&&d+e[i].w<dis[e[i].v])
//                 dis[e[i].v]=d+e[i].w,q.push(pii(d+e[i].w,e[i].v));
//     }
//     // for(ll i=1;i<=n+m;i++)
//     //     cout<<dis[i]<<' ';
    
// }
// ll ans[Q];
// vector<pii> tsk[M];
ll dis_[N][N];
signed main(void){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    c=read();n=read();m=read();d=read();q=read();
    ncnt=n+1;
    for(ll i=1;i<=m;i++)w[i]=read();
    for(ll i=1;i<=n;i++){
        k[i]=read();
        a[i].resize(k[i]+5);
        t[i].resize(k[i]+5);
        for(ll j=1;j<=k[i];j++){
            a[i][j]=read();
            t[i][j]=read();
            addEdge(m+i,a[i][j],t[i][j]);
            addEdge(a[i][j],m+i,t[i][j]);
        }
    }
    memset(dis_,0x3f,sizeof(dis_));
    for(ll i=1;i<=n;i++){// O(md)
        for(ll j=hed[m+i];j;j=e[j].nxt){
            for(ll k=hed[e[j].v];k;k=e[k].nxt){
                if(m+i==e[k].v)continue;
                // cout<<m+i<<' '<<e[j].v<<' '<<e[k].v<<'\n';
                dis_[i][e[k].v-m]=min(dis_[i][e[k].v-m],e[j].w+e[k].w);
            }
        }
    }
    for(ll i=1;i<=n;i++)
        dis_[i][i]=0;
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dis_[i][j]=min(dis_[i][j],dis_[i][k]+dis_[k][j]);
            }
        }
    }
    // for(ll i=1;i<=n;i++){
    //     for(ll j=1;j<=n;j++){
    //         cout<<dis_[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    pii uu[D],vv[D];
    ll ucnt,vcnt;
    while(q--){
        ll u,v;
        ll ans=1e+18;
        u=read();v=read();
        ucnt=0;vcnt=0;
        for(ll i=hed[u];i;i=e[i].nxt)
            uu[++ucnt]=pii(e[i].v,e[i].w);
        for(ll i=hed[v];i;i=e[i].nxt)
            vv[++vcnt]=pii(e[i].v,e[i].w);
        // cout<<ucnt<<' '<<vcnt<<'\n';
        for(ll i=1;i<=ucnt;i++){
            for(ll j=1;j<=vcnt;j++){
                // cout<<uu[i].x<<' '<<vv[j].x<<' ';
                ans=min(ans,uu[i].y+vv[j].y+dis_[uu[i].x-m][vv[j].x-m]);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}

*/