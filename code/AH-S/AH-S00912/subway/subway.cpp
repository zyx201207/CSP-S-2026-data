#include <bits/stdc++.h>
using namespace std;

const int N=505,M=5e5+5;
long long val[M],oo=1e18;
vector<pair<int,long long> >b[M];
int k[N];
long long dis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>val[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            int x;long long ti;
            cin>>x>>ti;
            b[x].push_back({i,ti});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=oo;
        }
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<b[i].size();j++){
            for(int z=j+1;z<b[i].size();z++){
                int u=b[i][j].first,v=b[i][z].first;
                long long g=b[i][j].second+b[i][z].second;
                dis[u][v]=min(dis[u][v],g);
                dis[v][u]=min(dis[v][u],g);
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
        int u,v;
        cin>>u>>v;
        long long dx=val[u]+val[v],rt=oo;
        for(int i=0;i<b[u].size();i++){
            for(int j=0;j<b[v].size();j++){
                long long g=b[u][i].second+b[v][j].second;
                rt=min(rt,g+dis[b[u][i].first][b[v][j].first]);
            }
        }
        cout<<dx+rt<<"\n";
    }
    return 0;
}