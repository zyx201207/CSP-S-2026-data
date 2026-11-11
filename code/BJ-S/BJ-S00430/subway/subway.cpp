#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=2e4+10;
int c,n,m,d,q,dis[N][N],w[M],k[N],a[M],t[M],tot,head[M],ver[M],nxt[M];
void add(int u,int v){
    tot++;
    ver[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    return ;
}
void dfs(int x,int fa,int vi){
    for(int i=head[x];i;i=nxt[i]){
        int v=ver[i];
        if(vi==v) continue;
        dis[fa][v]=min(dis[fa][v],dis[fa][x]+dis[x][v]);
        dis[v][fa]=dis[fa][v];
        dfs(v,fa,x);
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);

        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[j],&t[j]);
            for(int l=1;l<j;l++){
                if(dis[a[j]][a[l]]==dis[0][0]){
                    if(c>=7){
                        add(a[j],a[l]);
                        add(a[l],a[j]);
                    }
                }
                dis[a[j]][a[l]]=min(dis[a[j]][a[l]],t[j]+t[l]);
                dis[a[l]][a[j]]=dis[a[j]][a[l]];
            }
            dis[a[j]][a[j]]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dis[i][j]=min(dis[i][j],dis[j][i]);
        }
    }
    if(c<=6){
        for(int l=1;l<=m;l++)
            for(int i=1;i<=m;i++){
                for(int j=i+1;j<=m;j++){
                    dis[i][j]=min(dis[i][j],dis[l][i]+dis[l][j]);
                    dis[j][i]=dis[i][j];
                }
            }
    }
    else if(c>=7){
        for(int i=1;i<=m;i++){
            dfs(i,i,0);
        }
    }
    for(int i=1,x,y;i<=q;i++){
        scanf("%d%d",&x,&y);
        int ans=w[x]+w[y]+dis[x][y];
        printf("%d\n",ans);
    }
    return 0;
}

