#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long cost[500010];
struct Node{
    int v;
    long long w;
};
vector<Node> G[500010];
long long dis[510][510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&cost[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        while(k--){
            int pos;
            long long num;
            scanf("%d %lld",&pos,&num);
            G[pos].push_back((Node){i,num});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) dis[i][j]=0x3f3f3f3f3f3f3f3f;
            else dis[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<G[i].size();j++){
            for(int k=0;k<G[i].size();k++){
                dis[G[i][j].v][G[i][k].v]=min(dis[G[i][j].v][G[i][k].v],G[i][j].w+G[i][k].w);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int s,t;
        scanf("%d %d",&s,&t);
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<G[s].size();i++){
            for(int j=0;j<G[t].size();j++){
                ans=min(ans,cost[s]+cost[t]+G[s][i].w+G[t][j].w+dis[G[s][i].v][G[t][j].v]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}