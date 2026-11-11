#include<bits/stdc++.h>
using namespace std;

int n,m,d,q;
long long as;
long long w[500010];
long long dis[510][510];
long long tid[500010][30],ta[500010][30];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    scanf("%d",&n);
    scanf("%d%d%d%d",&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    int tp,x;
    long long y;
    for(int i=1;i<=n;i++){
        dis[i][i] = 0;
        scanf("%d",&tp);
        for(int j=1;j<=tp;j++){
            scanf("%d%lld",&x,&y);
            tid[x][++tid[x][0]] = i;
            ta[x][++ta[x][0]] = y;
        }
    }

    for(int k=1;k<=m;k++){
        for(int i=1;i<=ta[k][0];i++){
            for(int j=i+1;j<=ta[k][0];j++){
                dis[tid[k][i]][tid[k][j]] = min(dis[tid[k][i]][tid[k][j]],ta[k][i]+ta[k][j]);
                dis[tid[k][j]][tid[k][i]] = min(dis[tid[k][j]][tid[k][i]],ta[k][i]+ta[k][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",dis[i][j]);
        }
        puts("");
    }*/
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    long long inx,iny;
    while(q--){
        as = 8e18;
        scanf("%lld%lld",&inx,&iny);
        for(int i=1;i<=tid[inx][0];i++){
            for(int j=1;j<=tid[iny][0];j++){
                as = min(as,w[inx]+ta[inx][i]+dis[tid[inx][i]][tid[iny][j]]+ta[iny][j]+w[iny]);
            }
        }
        printf("%lld\n",as);
    }
    return 0;
}
