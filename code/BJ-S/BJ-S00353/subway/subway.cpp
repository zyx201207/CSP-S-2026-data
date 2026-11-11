#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005],k[505];
int dist[505][505];
int x,y,z,i,j,u;
struct stage{
    int num,cost;
};
vector<stage> t[500005];
void floyd(){
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            dist[i][j]=1000000000000;
        }
    }
    for(i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(i=1;i<=m;i++){
        z=t[i].size();
        for(j=0;j<z;j++){
            for(u=0;u<j;u++){
                if(j==u) continue;
                dist[t[i][j].num][t[i][u].num]=min(dist[t[i][j].num][t[i][u].num],t[i][j].cost+t[i][u].cost);
                dist[t[i][u].num][t[i][j].num]=dist[t[i][j].num][t[i][u].num];
            }
        }
    }
    for(x=1;x<=n;x++){
        for(y=1;y<x;y++){
            for(z=1;z<=n;z++){
                if(x==z||y==z) continue;
                dist[x][y]=min(dist[x][y],dist[x][z]+dist[y][z]);
                dist[y][x]=dist[x][y];
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(i=1;i<=m;i++){
        cin>>w[i];
    }
    for(i=1;i<=n;i++){
        cin>>k[i];
        for(j=1;j<=k[i];j++){
            cin>>x>>y;
            t[x].push_back({i,y});
        }
    }
    floyd();
    long long ans;
    while(q--){
        ans=1000000000000;
        cin>>x>>y;
        int a=t[x].size(),b=t[y].size();
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                ans=min(ans,t[x][i].cost+t[y][j].cost+dist[t[x][i].num][t[y][j].num]);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
