#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int c,n,m,d,q,w[500010];
set<int>b[1001];
map<int,int>ds[500010];
LL dis[1010][1010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%d",w+i);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a,t;scanf("%d%d",&a,&t);
            ds[i][a]=t;
            b[a].insert(i);
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            if(i==j)
                dis[i][j]=0;
            else
                dis[i][j]=1LL<<60;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++){
            if(i!=j){
                for(auto p:b[i])
                    if(b[j].count(p)){
                        LL x=ds[p][i]+ds[p][j];
                        dis[j][i]=dis[i][j]=min(dis[i][j],x);
                    }
            }
        }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=m;k++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        printf("%lld\n",dis[x][y]+w[x]+w[y]);
    }
}
