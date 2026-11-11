#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int dis[N][N];
int w[M];
vector<int>e[M],t[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,b;
            cin>>a>>b;
            e[a].push_back(i);
            t[a].push_back(b);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<e[i].size();j++){
            for(int k=j+1;k<e[i].size();k++){
                int x=e[i][j],y=e[i][k];
                dis[x][y]=min(dis[x][y],t[i][j]+t[i][k]);
                dis[y][x]=min(dis[y][x],t[i][j]+t[i][k]);
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
        int x,y;
        cin>>x>>y;
        int res=1e18;
        for(int j=0;j<e[x].size();j++){
            for(int k=0;k<e[y].size();k++){
                int p=e[x][j],q=e[y][k];
                res=min(res,w[x]+t[x][j]+dis[p][q]+t[y][k]+w[y]);
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}

