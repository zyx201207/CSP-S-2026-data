#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long inf=1e18;
long long dis[505][505];
int w[500005];
struct node1{
    long long line,time;
};
vector<node1> g[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            g[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=inf;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int l=0;l<g[i].size();l++){
            for(int r=0;r<g[i].size();r++){
                int L=g[i][l].line;
                int R=g[i][r].line;
                dis[L][R]=min(dis[L][R],g[i][l].time+g[i][r].time);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l<=n;l++){
            for(int r=1;r<=n;r++){
                dis[l][r]=min(dis[l][i]+dis[i][r],dis[l][r]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=inf;
        for(int i=0;i<g[x].size();i++){
            for(int j=0;j<g[y].size();j++){
                int l=g[x][i].line,r=g[y][j].line;
                ans=min(ans,g[x][i].time+g[y][j].time+dis[l][r]+w[x]+w[y]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
