#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int a1[N];
int dis[505][505];
struct nope{
    int x,y;
};
vector<nope> vec[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a1[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            vec[x].push_back(nope{i,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e16;
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<vec[i].size();j++){
            for(int k=j+1;k<vec[i].size();k++){
                int u=vec[i][j].x,v=vec[i][k].x;
                int w1=vec[i][j].y,w2=vec[i][k].y;
                dis[u][v]=min(dis[u][v],w1+w2);
                dis[v][u]=min(dis[v][u],w1+w2);
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
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        int mmin=1e18;
        for(int j=0;j<vec[u].size();j++){
            for(int k=0;k<vec[v].size();k++){
                int u1=vec[u][j].x,v1=vec[v][k].x;
                int w1=vec[u][j].y,w2=vec[v][k].y;
                mmin=min(mmin,a1[u]+a1[v]+w1+w2+dis[u1][v1]);
            }
        }
        cout<<mmin<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
