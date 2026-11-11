#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int c,n,m,d,q,k,dis[10000][10000];
pair<int,int> pce[100010];
unsigned long long talp;

void floyd(){
    for(ull k=1;k<=talp;k++){
        for(ull i=1;i<=talp;i++){
            for(ull j=1;j<=talp;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }            
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof dis);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    talp=n+2*m;int x,y;
    for(int i=1;i<=n+2*m;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        dis[i+n][i+n+m]=x;
        dis[i+n+m][i+n]=x;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&y);
            scanf("%d",&x);
            dis[i][y+n+m]=x;
            dis[y+n+m][i]=x;
        }
    }
    for(int i=1;i<=q;i++)scanf("%d%d",&pce[i].first,&pce[i].second);
    floyd();
    for(int i=1;i<=q;i++)printf("%d\n",dis[pce[i].first+n][pce[i].second+n]);
    return 0;
}