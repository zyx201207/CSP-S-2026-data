#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 505, M = 500005;
int cid,n,m,mxd,q;
int wt[M];
ll dis[N][N];
vector<pair<int,int> > sta[M];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> cid >> n >> m >> mxd >> q;
    memset(dis,0x3f,sizeof(dis));
    for (int i = 1; i <= m; i++){
        cin >> wt[i];
    }
    for (int i = 1; i <= n; i++){
        int ki; cin >> ki;
        for (int j = 1; j <= ki; j++){
            int a,t; cin >> a >> t;
            sta[a].push_back(make_pair(i,t));
        }
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < (int)sta[i].size(); j++){
            for (int k = j+1; k < (int)sta[i].size(); k++){
                int u = sta[i][j].first, v = sta[i][k].first;
                ll w = sta[i][j].second + sta[i][k].second;
                dis[u][v] = min(dis[u][v], w);
                dis[v][u] = min(dis[v][u], w);
                //printf("sta %d %d %lld\n", u, v, w);
            }
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    while (q--){
        int u,v; cin >> u >> v;
        ll ans = 2e18;
        for (int i = 0; i < (int)sta[u].size(); i++){
            for (int j = 0; j < (int)sta[v].size(); j++){
                ans = min(ans, dis[sta[u][i].first][sta[v][j].first] + sta[u][i].second + sta[v][j].second);
            }
        }
        ans += wt[u] + wt[v];
        cout << ans << '\n';
    }
    return 0;
}
