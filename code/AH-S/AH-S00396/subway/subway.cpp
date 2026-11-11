#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
struct edge{ int next,w; }to[M][25];
int C,n,m,d,q,ans;
int val[M],g[N][N],p[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) scanf("%lld",&val[i]);
    for(int i=1,k;i<=n;i++){
        scanf("%lld",&k);
        for(int j=1,u,w;j<=k;j++){
            scanf("%lld%lld",&u,&w);
            to[u][++p[u]]={i,w};
        }
    }
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=n;i++) g[i][i]=0;
    for(int i=1,u,v;i<=m;i++){
        for(int l=1;l<=p[i];l++){
            for(int r=l+1;r<=p[i];r++){
                u=to[i][l].next,v=to[i][r].next;
                g[u][v]=g[v][u]=min(g[u][v],to[i][l].w+to[i][r].w);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    for(int i=1,u,v;i<=q;i++){
        ans=1e18;
        scanf("%lld%lld",&u,&v);
        for(int l=1;l<=p[u];l++){
            for(int r=1;r<=p[v];r++){
                edge x=to[u][l],y=to[v][r];
                ans=min(ans,g[x.next][y.next]+x.w+y.w);
            }
        }
        printf("%lld\n",ans+val[u]+val[v]);
    }
    return 0;
}
