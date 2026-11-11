#include <bits/stdc++.h>
#define int long long
#define pii pair <int, int>
#define fi first
#define se second
using namespace std;
const int N = 505, M = 5e5 + 5;
const int INF = 1e18; 
vector <pii> p[M]; 
int a[M], f[N][N]; 
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout); 
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0); 
    int _, n, m, d, q; cin >> _ >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int s; cin >> s;
        for (int j = 1, x, y; j <= s; j++)
            cin >> x >> y, p[x].push_back({i, y}); 
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++)
        for (auto j : p[i])
            for (auto k : p[i])
                f[j.fi][k.fi] = min(f[j.fi][k.fi], j.se + k.se);
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--) {
        int x, y, ans = INF; cin >> x >> y;
        for (auto i : p[x])
            for (auto j : p[y]) 
                ans = min(ans, i.se + j.se + f[i.fi][j.fi]); 
        cout << ans + a[x] + a[y] << '\n'; 
    }
    return 0; 
}