#include<bits/stdc++.h>
using namespace std;
const long long INF=1e16;
long long c,n,m,d,q,ans;
long long a[500005];
struct node{
    long long v,w;
};
long long e[505][505];
vector<node> zh[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i){
                e[i][j]=0;
            }else{
                e[i][j]=INF;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int k,v,w,u=i;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>v>>w;
            zh[v].push_back({u,w});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<zh[i].size();j++){
            for(int k=j+1;k<zh[i].size();k++){
                long long u=zh[i][j].v,v=zh[i][k].v,w=zh[i][j].w+zh[i][k].w;
                e[u][v]=min(e[u][v],w);
                e[v][u]=min(e[v][u],w);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ans=INF;
        for(int i=0;i<zh[x].size();i++){
            for(int j=0;j<zh[y].size();j++){
                long long u=zh[x][i].v,v=zh[y][j].v,w=zh[x][i].w+zh[y][j].w;
                ans=min(ans,e[u][v]+w);
            }
        }
        cout<<ans+a[x]+a[y]<<"\n";
    }
    return 0;
}

