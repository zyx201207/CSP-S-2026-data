#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int c,n,m,d,q,x,y,ans;
int w[500005],kk[500005];
int dis[20002][20002];
vector<pii> g[500005];
int main(){
    memset(dis,0x3f,sizeof(dis));
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%d",w+i);
    for(int i=1;i<=n;i++){
        scanf("%d",kk+i);
        for(int j=1;j<=kk[i];j++){
            scanf("%d%d",&x,&y);
            g[i].push_back({x,y});
        }
        for(pii j:g[i])
            for(pii k:g[i]){
                int t1=j.first,t2=k.first;
                dis[t1][t2]=min(dis[t1][t2],j.second+k.second);
            }
    }
    for(int i=1;i<=m;i++)dis[i][i]=0;
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        scanf("%d%d",&x,&y);
        ans=w[x]+w[y]+dis[x][y];
        printf("%d\n",ans);
    }
}