#include <bits/stdc++.h>
using namespace std;
#define int long long
int c , n , m , d , q;
int w[500005] , k[505];
vector<int>a[505] , t[505];
vector<pair<int , int>>to[500005];
int g[505][505];
signed main(){
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++){
            int x , y;
            cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
            to[x].push_back({i , y});
        }
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            g[i][j] = 1e12;
    int INF = g[0][0];
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < to[i].size(); j++){
            for (int p = j + 1; p < to[i].size(); p++){
                int x = to[i][j].first , y = to[i][p].first;
                int l = to[i][j].second + to[i][p].second;
                if (l < g[x][y]){
                    g[x][y] = l;
                }
                if (l < g[y][x]){
                    g[y][x] = l;
                }
            }
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (g[i][j] > g[i][k] + g[k][j] || g[i][j] == INF){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) g[i][i] = 0;
    while(q--){
        int x , y;
        cin >> x >> y;
        int ans = INF;
        for (int i = 0; i < to[x].size(); i++){
            for (int j = 0; j < to[y].size(); j++){
                ans = min(ans , g[to[x][i].first][to[y][j].first] + to[x][i].second + to[y][j].second);
            }
        }
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}
