#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5, M = 5e5 + 5;
long long C, n, m, d, q, w[M], k[N], dis[N][N];
vector<pair<long long, long long> > a[M];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dis, 0x3f, sizeof dis);
    cin >> C >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++)
        cin >> w[i];
    for (int i = 1; i <= n; i ++){
        cin >> k[i];
        for (int j = 1, u, v; j <= k[i]; j ++){
            cin >> u >> v;
            a[u].push_back(make_pair(i, v));
        }
    }
    for (int i = 1; i <= n; i ++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i ++)
        for (int l = 0; l < a[i].size(); l ++)
            for (int r = 0; r < a[i].size(); r ++)
                dis[a[i][l].first][a[i][r].first] = min(dis[a[i][l].first][a[i][r].first], a[i][l].second + a[i][r].second);
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q --){
        long long x, y, ans = 1e18;
        cin >> x >> y;
        for (int i = 0; i < a[x].size(); i ++)
            for (int j = 0; j < a[y].size(); j ++)
                ans = min(ans, dis[a[x][i].first][a[y][j].first] + a[x][i].second + a[y][j].second);
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}
