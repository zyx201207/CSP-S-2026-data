#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 505;
constexpr int M = 500005;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, k[N], d, q, w[M];
vector<pair<int, int>> bridge[M];
int f[N][N];

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i ++)
        cin >> w[i];
    for(int i = 1; i <= n; i ++){
        cin >> k[i];
        int a, t;
        for(int j = 1; j <= k[i]; j ++){
            cin >> a >> t;
            bridge[a].emplace_back(make_pair(i, t));
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            f[i][j] = (i == j? 0: INF);
    for(int i = 1; i <= m; i ++){
        for(auto u: bridge[i])
        for(auto v: bridge[i]){
            const int x = u.first, y = v.first, t = u.second + v.second;
            f[x][y] = min(f[x][y], t);
            f[y][x] = min(f[y][x], t);
        }
    }
    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    int x, y;
    while(q--){
        cin >> x >> y;
        int ans = INF;
        for(auto u: bridge[x])
        for(auto v: bridge[y]){
            const int uu = u.first, vv = v.first, tt = u.second + v.second;
            ans = min(ans, f[uu][vv] + tt);
        }
        cout << (ans + w[x] + w[y]) << endl;
    }
    return 0;
}
