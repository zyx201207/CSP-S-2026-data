#include <bits/stdc++.h>
using namespace std;
long long w[1005],k[2][21],f[1005][1005];
int main(){
    memset(f,0x3f,sizeof(f));
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,ki;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i = 1;i <= m;i++){
        f[i][i] = 0;
    }
    for(int i = 1;i <= n;i++){
        scanf("%d",&ki);
        for(int j = 1;j <= ki;j++){
            scanf("%lld%lld",&k[0][j],&k[1][j]);
        }
        for(int u = 1;u <= ki;u++){
            for(int v = u + 1;v <= ki;v++){
                int st = k[0][u],ed = k[0][v];
                f[st][ed] = min(f[st][ed],k[1][u] + k[1][v]);
                f[ed][st] = min(f[ed][st],k[1][u] + k[1][v]);
            }
        }
    }
    if(c <= 11){
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= m;j++){
                for(int k = 1;k <= m;k++){
                    f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
                }
            }
        }
        for(int i = 1,u,v;i <= q;i++){
            scanf("%d%d",&u,&v);
            printf("%lld\n",f[u][v] + w[u] + w[v]);
        }
    }
    return 0;
}
