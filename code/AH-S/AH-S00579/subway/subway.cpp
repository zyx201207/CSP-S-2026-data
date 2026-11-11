#include<bits/stdc++.h>
using namespace std;
long long w[500005];
struct Node{
    int y;
    long long w;
};
vector<Node> zhan[500005];
long long dist[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                dist[i][j]=LLONG_MAX;
                dist[j][i]=LLONG_MAX;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x;
            long long y;
            scanf("%d%lld",&x,&y);
            for(int p=0;p<zhan[x].size();p++){
                Node t=zhan[x][p];
                dist[t.y][i]=min(dist[t.y][i],t.w+y);
                dist[i][t.y]=dist[t.y][i];
            }
            zhan[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i!=k && j!=k){
                    if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX){
                        if(dist[i][j]>dist[i][k]+dist[k][j]){
                            dist[i][j]=dist[i][k]+dist[k][j];
                            dist[j][i]=dist[i][k]+dist[k][j];
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        long long mn=LLONG_MAX;
        for(int j=0;j<zhan[x].size();j++){
            int t1=zhan[x][j].y;
            for(int p=0;p<zhan[y].size();p++){
                int t2=zhan[y][p].y;
                if(dist[t1][t2]!=LLONG_MAX){
                    mn=min(mn,dist[t1][t2]+w[x]+w[y]+zhan[x][j].w+zhan[y][p].w);
                }
            }
        }
        cout<<mn<<"\n";
    }
    return 0;
}
