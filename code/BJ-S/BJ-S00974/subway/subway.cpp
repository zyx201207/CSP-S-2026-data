#include<bits/stdc++.h>
using namespace std;
const int NR=505,MR=5e5+5;
int C,n,m,D,q;
int a[MR];
int nxt[2*MR],head[MR+NR],to[2*MR],w[2*MR],ecnt;
void add(int u,int v,int _w){
    nxt[++ecnt]=head[u];
    head[u]=ecnt;
    to[ecnt]=v,w[ecnt]=_w;
}
long long f[NR][NR];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&C,&n,&m,&D,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        while(k--){
            int x,y;
            scanf("%d %d",&x,&y);
            add(m+i,x,y);
            add(x,m+i,y);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=4e18;
        }
        f[i][i]=0;
    }
    for(int x=1;x<=n;x++){
        for(int i=head[x+m];i;i=nxt[i]){
            for(int j=head[to[i]];j;j=nxt[j]){
                int y=to[j]-m;
                long long t=min(f[x][y],1ll*w[i]+w[j]);
                f[x][y]=t;
                f[y][x]=t;
            }
        }
    }
    floyd();
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        long long ans=9e18;
        for(int i=head[x];i;i=nxt[i]){
            for(int j=head[y];j;j=nxt[j]){
                ans=min(ans,f[to[i]-m][to[j]-m]+w[i]+w[j]);
            }
        }
        printf("%lld\n",ans+a[x]+a[y]);
    }
    return 0;
}
