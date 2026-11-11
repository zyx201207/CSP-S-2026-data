/*
g++ subway.cpp -o exe -Wall -O2
time ./exe
diff subway7.ans subway.out

*/
#include<bits/stdc++.h>
using namespace std;
int n,m,d,q;
long long dist[510][510];
long long ax[500010];
struct Node{
    int id;
    long long dis;
};
vector<Node> tr[500010];
void Floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(k==i){
                continue;
            }
            for(int j=1;j<=n;j++){
                if(j==i||j==k){
                    continue;
                }
                dist[j][i]=dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&n,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&ax[i]);
    }
    for(int i=1;i<=n;i++){
        int siz;
        scanf("%d",&siz);
        for(int j=1;j<=siz;j++){
            int u;
            long long D;
            scanf("%d%lld",&u,&D);
            tr[u].push_back({i,D});
        }
    }
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;i++){
        dist[i][i]=0ll;
    }
    for(int i=1;i<=m;i++){
        for(Node u:tr[i]){
            for(Node v:tr[i]){
                if(u.id==v.id){
                    continue;
                }
                dist[v.id][u.id]=dist[u.id][v.id]=min(dist[u.id][v.id],u.dis+v.dis);
            }
        }
    }
    Floyd();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("dis[%d][%d]=%d ",i,j,dist[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans=100000000000000000;
        for(Node u:tr[x]){
            for(Node v:tr[y]){
                ans=min(ans,dist[u.id][v.id]+u.dis+v.dis);
            }
        }
        printf("%lld\n",ans+ax[x]+ax[y]);
    }
    return 0;
}
