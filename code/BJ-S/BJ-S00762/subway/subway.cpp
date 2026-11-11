/*
def f[i][j]=dist line i->j
query (u,v):
ans=a[u]+a[v]+min(g[i][u] + f[i][j] + g[j][v]), where i,j are lines connecting to u,v; O(qd^2)
find f:
1. f[i][j] = dist i->j in one step
for station u, update f[i][j]=min(g[i][u]+g[j][u]) O(m*d^2) // FASTER?
then run Floyd / Dijkstra (O(MlogM))
total: O((m+q)d^2+O(n^2logn))
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
struct E{int id,w;}; // line, dist
int c,n,m,d,q;
int a[M];
ll f[N][N];
vector<E> g[M]; // push 20, O(md)
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int u,w;scanf("%d%d",&u,&w);
            g[u].push_back({i,w});
        }
    }
    // init f
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    // find f[i][j] in one step
    for(int u=1;u<=m;u++){
        for(int i=0;i<g[u].size();i++){
            for(int j=i+1;j<g[u].size();j++){
                int x=g[u][i].id,y=g[u][j].id;
                ll nd=g[u][i].w+g[u][j].w;
                f[x][y]=min(f[x][y],nd),f[y][x]=f[x][y];
            }
        }
    }
    // find f[i][j] in multiple steps
    for(int k=1;k<=n;k++){
        // i->[1,k]->j shortest length
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                // i->[1,k-1]->k, k->[1,k-1]->j alrady known
                // update with i->k->j
                if(f[i][k]>1e18||f[k][j]>1e18) continue; // unreachable
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]),f[j][i]=f[i][j];
            }
        }
    }
    /*
    // test
    for(int i=1;i<=m;i++){
        for(auto [id,w]:g[i]) printf("(%d,%d) ",id,w);
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",f[i][j]);
        }
        printf("\n");
    }
    */
    for(int i=1;i<=q;i++){
        int u,v;scanf("%d%d",&u,&v);
        // answer
        ll ans=1e18;
        for(int i=0;i<g[u].size();i++){
            for(int j=0;j<g[v].size();j++){
                int x=g[u][i].id,y=g[v][j].id;
                ll nd=g[u][i].w+g[v][j].w;
                ans=min(ans,nd+f[x][y]);
            }
        }
        ans+=(a[u]+a[v]);
        printf("%lld\n",ans);
    }
    return 0;
}