#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5 + 5, D = 22;
vector<pair<int, int>> tim[M]; 
int k[N], w[M]; long long dis[N][N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    int C, n, m, d, q; cin >> C >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++) {
        cin >> k[i];
        for(int j = 1, x, y;j <= k[i];j++) {
            cin >> x >> y;
            tim[x].push_back({i, y});
        }
    } for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            dis[i][j] = 1e15;
    for(int i = 1;i <= n;i++) dis[i][i] = 0;
    for(int i = 1;i <= m;i++) {
        int siz = tim[i].size();
        //0 ~ siz - 1
        for(int j = 0;j < siz - 1;j++)
            for(int k = j+1;k <= siz - 1;k++) {
                int u = tim[i][j].first, v = tim[i][k].first;
                long long wu = tim[i][j].second, wv = tim[i][k].second;
                dis[u][v] = min(dis[u][v], wu + wv);
                dis[v][u] = min(dis[v][u], wu + wv);
            }
    } for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while(q--) {
        int st, ed; cin >> st >> ed; long long ans = 1e15;
        for(int i = 0;i < tim[st].size();i++)
            for(int j = 0;j < tim[ed].size();j++)
                ans = min(ans, dis[tim[st][i].first][tim[ed][j].first] + tim[st][i].second + tim[ed][j].second);
        cout << (ans + w[st] + w[ed]) << "\n";
    }
    return 0;
}
//15:07
//Computers are fast nowadays