#include <bits/stdc++.h>
#define llong long long
#define N 505
#define M 500005
using namespace std;

constexpr llong inf = (llong)1e18+3;

int c, n, m, d, q;
vector<pair<int,llong>> a[M];
llong w[M];

llong G[N][N];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i) cin >> w[i];
    for(int i = 1; i <= n; ++i)
        for(int j = i+1; j <= n; ++j)
            G[i][j] = G[j][i] = inf;
    for(int i = 1; i <= n; ++i){
        int k; cin >> k;
        for(int j = 1; j <= k; ++j){
            int x; llong y;
            cin >> x >> y;
            a[x].emplace_back(i, y);
        }
    }
    for(int i = 1; i <= m; ++i){
        int k = a[i].size();
        for(int j1 = 0; j1 < k; ++j1){
            int x = a[i][j1].first;
            llong w1 = a[i][j1].second;
            for(int j2 = 0; j2 < k; ++j2){
                int y = a[i][j2].first;
                llong w2 = a[i][j2].second;
                G[x][y] = G[y][x] = (G[x][y]<w1+w2 ? G[x][y] : w1+w2);
            }
        }
    }
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
    while(q--){
        int x, y; cin >> x >> y;
        llong ans = inf;
        int k1 = a[x].size(), k2 = a[y].size();
        for(int i = 0; i < k1; ++i)
            for(int j = 0; j < k2; ++j)
                ans = min(ans, G[a[x][i].first][a[y][j].first]+a[x][i].second+a[y][j].second);
        ans += w[x]+w[y];
        cout << ans << "\n";
    }
    return 0;
}
