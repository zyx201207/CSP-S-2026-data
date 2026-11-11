#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>pii;
#define fi first
#define se second
const int N = 510;
const int M = 5e5+10;
int dis[N][N];
int c,n,m,d,q;
int w[M];
vector<pii>p[M];//line

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++)cin>>w[i];
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i<=n;i++)dis[i][i] = 0;
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        for(int j = 1;j<=k;j++){
            int u,t;
            cin>>u>>t;
            p[u].push_back({i,t});
        }
    }
    for(int i = 1;i<=m;i++){
        for(int j = 0;j<(int)p[i].size();j++){
            for(int k = j+1;k<(int)p[i].size();k++){
                int u = p[i][j].fi,t1 = p[i][j].se;
                int v = p[i][k].fi,t2 = p[i][k].se;
                dis[u][v] = min(dis[u][v],t1+t2);
                dis[v][u] = min(dis[v][u],t1+t2);
            }
        }
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans = 1e18;
        for(auto o1:p[x]){
            for(auto o2:p[y]){
                int u = o1.fi,t1 = o1.se;
                int v = o2.fi,t2 = o2.se;
                ans = min(ans,dis[u][v]+t1+t2+w[x]+w[y]);
            }
        }
        cout<<ans<<"\n";
    }



    return 0;
}