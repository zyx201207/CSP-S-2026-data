#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Ror(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;using ll=long long;
const int N=5e5+10,M=510;
int c,n,m,d,q;ll w[N],ans;unordered_map<ll,int>tim;
vector<ll>a[N];//record station belong what route
ll f[M][M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(f,0x3f,sizeof(f));
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    For(i,1,m)scanf("%lld",&w[i]);
    For(i,1,n){
        int k;scanf("%d",&k);
        For(j,1,k){
            int x,y;scanf("%d%d",&x,&y);
            tim[1ll*x*5000+i]=y;
            for(int z:a[x]){
                f[z][i]=y+tim[1ll*x*5000+z];
                f[i][z]=y+tim[1ll*x*5000+z];
            }
            a[x].push_back(i);
        }
    }
    For(i,1,n)f[i][i]=0;
    For(k,1,n)For(i,1,n)For(j,1,n)f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
//    For(i,1,n){For(j,1,n)printf("%lld ",f[i][j]);puts("");}
    For(i,1,q){
        int x,y;scanf("%d%d",&x,&y);ll ans=1e18;
        for(int u:a[x])for(int v:a[y])
            ans=min(f[u][v]+tim[1ll*x*5000+u]+tim[1ll*y*5000+v]+w[x]+w[y],ans);
        printf("%lld\n",ans);
    }
    return 0;
}

