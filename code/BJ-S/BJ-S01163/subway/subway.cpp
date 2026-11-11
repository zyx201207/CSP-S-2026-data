#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M];
struct node{
    int x,y;
};
vector<node>ve[M];
int dis[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            ve[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1e18;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<ve[i].size();j++){
            for(int k=j+1;k<ve[i].size();k++){
                node u=ve[i][j],v=ve[i][k];
                dis[u.x][v.x]=min(dis[u.x][v.x],u.y+v.y);
                dis[v.x][u.x]=dis[u.x][v.x];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<i;j++)dis[i][j]=dis[j][i];
    while(q--){
        int x,y;cin>>x>>y;
        int ans=1e18;
        for(int i=0;i<ve[x].size();i++){
            for(int j=0;j<ve[y].size();j++){
                node u=ve[x][i],v=ve[y][j];
                ans=min(ans,dis[u.x][v.x]+u.y+v.y);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}
