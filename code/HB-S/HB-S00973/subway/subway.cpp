#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define mpr make_pair
const int N=5e5+5;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int cid,n,m,d,q,w[N];

// namespace solve1{
//     const int M=305,inf=1e18;

//     int tot;
//     int dis[M*2][M*2];

//     void solve(){
//         tot=m;
//         for(int i=1;i<=n+m;++i){
//             for(int j=1;j<=n+m;++j){
//                 dis[i][j]=inf;
//             }
//             dis[i][i]=0;
//         }
//         for(int i=1;i<=n;++i){
//             int k=read();++tot;
//             for(int j=1;j<=k;++j){
//                 int v=read(),t=read();
//                 dis[tot][v]=dis[v][tot]=t;
//             }
//         }
//         for(int c=1;c<=tot;++c)
//             for(int a=1;a<=tot;++a)
//                 for(int b=1;b<=tot;++b)
//                     dis[a][b]=min(dis[a][b],dis[a][c]+dis[c][b]);
//         for(int i=1;i<=q;++i){
//             int x=read(),y=read();
//             print(dis[x][y]+w[x]+w[y]);putchar('\n');
//         }
//     }
// }

// namespace solve2{
//     const int M=1005,inf=1e18;
//     int tot,h[M*2];
//     struct edge{
//         int nxt,to,w;
//     }e[M*2];

//     void adde(int u,int v,int w){
//         static int i=0;
//         e[++i].nxt=h[u];
//         h[u]=i;
//         e[i].to=v;
//         e[i].w=w;
//     }

//     int dis[M*2];
//     int qdis[M][M];
//     bool vis[M*2];
//     priority_queue<pii,vector<pii>,greater<pii> > qu;

//     void dij(int st){
//         for(int i=1;i<=m;++i)dis[i]=inf,vis[i]=0;
//         dis[st]=0;qu.push(mpr(0,st));
//         while(!qu.empty()){
//             int u=qu.top().second;qu.pop();
//             if(vis[u])continue;
//             vis[u]=1;
//             for(int i=h[u],v;i;i=e[i].nxt){
//                 v=e[i].to;
//                 if(dis[v]>dis[u]+e[i].w){
//                     dis[v]=dis[u]+e[i].w;
//                     qu.push(mpr(dis[v],v));
//                 }
//             }
//         }
//     }

//     void solve(){
//         for(int i=1;i<=n;++i){
//             read();
//             int x,y,w;
//             x=read();w=read();y=read();w+=read();
//             adde(x,y,w);adde(y,x,w);
//         }
//         for(int i=1;i<=m;++i){
//             dij(i);
//             for(int j=1;j<=m;++j){
//                 qdis[i][j]=dis[j];
//             }
//         }
//         for(int i=1;i<=q;++i){
//             int x=read(),y=read();
//             print(qdis[x][y]+w[x]+w[y]);putchar('\n');
//         }
//     }
// }

namespace solve3{
    const int M=505,D=22,inf=1e18;
    vector<pii> b[N];
    int dis[M][M];

    void solve(){
        for(int i=1;i<=n;++i){
            int k=read();
            for(int j=1;j<=k;++j){
                int a=read(),w=read();
                b[a].push_back(mpr(i,w));
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j)dis[i][j]=inf;
            dis[i][i]=0;
        }
        for(int i=1;i<=m;++i){
            for(pii x:b[i]){
                for(pii y:b[i]){
                    dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
                }
            }
        }
        for(int c=1;c<=n;++c)
            for(int a=1;a<=n;++a)
                for(int b=1;b<=n;++b)
                    dis[a][b]=min(dis[a][b],dis[a][c]+dis[c][b]);
        for(int i=1;i<=q;++i){
            int x=read(),y=read(),ans=inf;
            for(pii xx:b[x]){
                for(pii yy:b[y]){
                    ans=min(ans,dis[xx.first][yy.first]+xx.second+yy.second);
                }
            }
            print(ans+w[x]+w[y]);putchar('\n');
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cid=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;++i)w[i]=read();
    solve3::solve();
    return 0;
}