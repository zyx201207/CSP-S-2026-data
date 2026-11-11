#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q,k,a[5005],u,v;
ll w[5005],dis[5005][5005],t[5005];
ll solve(int u,int v) {
    return w[u]+dis[u][v]+w[v];
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=m;j++)
            dis[i][j]=0x3f3f3f3f3f3f3f3f;
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&k);
        for(int j=1;j<=k;j++) {
            scanf("%d%lld",&a[j],&t[j]);
            for(int l=1;l<j;l++)
                dis[a[l]][a[j]]=dis[a[j]][a[l]]=min(dis[a[l]][a[j]],t[l]+t[j]);
        }
    }
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    for(int i=1;i<=q;i++) {
        scanf("%d%d",&u,&v);
        printf("%lld\n",solve(u,v));
    }
    return 0;
}