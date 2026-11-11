#include <bits/stdc++.h>
using namespace std;
int w[514514];
int t[514514];
int g[54][54];
int main(){ 
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout); 
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m+n;i++){
        for(int j=1;j<=m+n;j++){
            g[i][j]=1e9;
            if(i==j){g[i][j]=0;}
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    int k,aij,tij,aij1;
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            aij1=aij;
            scanf("%d%d",&aij,&tij);
            if(j>=2){
                g[aij][aij1]=0;
                g[aij1][aij]=0;
            }
            g[i+m][aij]=min(g[i+m][aij],tij);
            g[aij][i+m]=min(g[aij][i+m],tij);
        }
    }
    for(int i=1;i<=m+n;i++){
        for(int j=1;j<=m+n;j++){
            for(int k=1;k<=m+n;k++){
                if(g[i][j]>g[i][k]+g[k][j]){
                    g[i][j]=g[i][k]+g[k][j]; 
                }
            }
        }
    }
    for(int kkk=1;kkk<=q;kkk++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",w[x]+w[y]+g[x][y]);
    }
    return 0;
}
