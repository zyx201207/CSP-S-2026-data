#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505 , M = 5e5 + 5;
int dis[N][N] , n , m , d , q , tp;
int w[M];
vector<pair<int,int> > vec[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> tp >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)cin >> w[i];
    for(int i=1;i<=n;i++){
        int k;cin >> k;
        for(int j=1;j<=k;j++){
            int to , ti;cin >> to >> ti;
            vec[to].push_back({i,ti});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i] = 0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<vec[i].size();j++){
            for(int k=j+1;k<vec[i].size();k++){
                int u = vec[i][j].first , w1 = vec[i][j].second , v = vec[i][k].first , w2 = vec[i][k].second;
                dis[u][v] = min(dis[u][v],w1+w2) , dis[v][u] = min(dis[v][u],w1+w2);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--){
        int s , t;cin >> s >> t;
        int ans = 1e18;
        for(int i=0;i<vec[s].size();i++){
            for(int j=0;j<vec[t].size();j++){
                ans = min(ans,w[s]+w[t]+dis[vec[s][i].first][vec[t][j].first]+vec[s][i].second+vec[t][j].second);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}