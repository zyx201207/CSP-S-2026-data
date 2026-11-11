#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10,M=510,D=25;
int c,n,m,d,q,w[N],f[M][M];
//n:zhan'de'shu'liang  m:xian'lu'shu'liang
int tot;
struct node{
    int v,w;
};
vector<node> G[M+N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&m,&n,&d,&q),tot=n+m;
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
    for(int i=1,k;i<=m;i++){
        scanf("%lld",&k);
        for(int j=1,a,t;j<=k;j++){
            scanf("%lld%lld",&a,&t);
            G[a].push_back((node){i+n,t});
            G[i+n].push_back((node){a,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=LLONG_MAX/2;
        }
        f[i][i]=0;
    }
    for(int u=1;u<=m;u++){
        for(int i=0;i<G[n+u].size();i++){//O(5e5)
            int tmp=G[n+u][i].v,w=G[n+u][i].w;
            for(int k=0;k<G[tmp].size();k++){//O(20)
                int v=G[tmp][k].v-n,w2=G[tmp][k].w;
                f[u][v]=f[v][u]=min(f[u][v],w+w2);
            /*if(u!=v){
                printf("%d %d %d\n",u,v,f[u][v]);
            }*/
            }
        }
    }//O(5e5*20)=O(1e7)
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }//O(500*500*500)=O(1.25e8)
    /*for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",f[i][j]);
        }
        puts("");
    }*/
    while(q--){
        int u,v,ans=LLONG_MAX/2;
        scanf("%lld%lld",&u,&v);
        for(int i=0;i<G[u].size();i++){//O(20*20)=O(400)
            int x=G[u][i].v-n,w1=G[u][i].w;
            for(int j=0;j<G[v].size();j++){//O(20)
                int y=G[v][j].v-n,w2=G[v][j].w;
                ans=min(ans,w1+f[x][y]+w2);
            }
        }
        ans+=w[u]+w[v];
        printf("%lld\n",ans);
    }//O(1e5*4e2)=O(4e7)
    return 0;
}
