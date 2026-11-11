#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 505
#define MAXM 500005

int cid, n, m, d, q; int w[MAXM], f[MAXN][MAXN]; vector<pair<int, int>> e[MAXM];

signed main(){
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> cid >> n >> m >> d >> q; for (int i(1); i<=m; ++i) cin >> w[i];
    for (int i(1), k; i<=n; ++i){
        cin >> k; for (int x, y; k; --k) cin >> x >> y, e[x].push_back({i, y});
    }
    // for (int i(1); i<=m; ++i) assert(e[i].size() <= d);
    memset(f, 0x3f, sizeof(f)); for (int i(1); i<=n; ++i) f[i][i] = 0;
    for (int i(1); i<=m; ++i){
        for (auto [a, b]: e[i]) for (auto [c, d]: e[i]) if (a ^ c) f[a][c] = min(f[a][c], b+d);
    }
    for (int k(1); k<=n; ++k) for (int i(1); i<=n; ++i) for (int j(1); j<=n; ++j) f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
    // cerr << f[1][2] << '\n';
    for (int x, y; q; --q){
        cin >> x >> y; int ans(1e18);
        for (auto [a, b]: e[x]) for (auto [c, d]: e[y]) ans = min(ans, f[a][c]+b+d);
        cout << ans+w[x]+w[y] << '\n';
    }

    return 0;
}