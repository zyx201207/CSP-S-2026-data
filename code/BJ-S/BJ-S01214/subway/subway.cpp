#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int e[2010][2010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a,t;
            scanf("%d%d",&a,&t);
            e[m+i][a]=t;
            e[a][m+i]=t;
        }
    }
    for(int i=1;i<=m+n;i++)
        for(int j=1;j<=m+n;j++)
            if(i!=j){
                for(int k=1;k<=m+n;k++)
                    e[i][j]=e[j][i]=min(e[i][j],e[i][k]+e[k][j]);
            }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",e[x][y]+w[x]+w[y]);
    }
    return 0;
}
