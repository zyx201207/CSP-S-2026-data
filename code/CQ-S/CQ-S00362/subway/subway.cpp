#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 510, N = 5e5 + 10, inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q; vector <pair <int, int> > sta[N];
int w[N], a[N], t[N]; int f[M][M];
signed main() { cin.tie(nullptr) -> ios::sync_with_stdio(0);
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int p = 1; p <= n; p++) {
        int k; cin >> k;
        for (int i = 1; i <= k; i++) cin >> a[i] >> t[i], sta[a[i]].emplace_back(p, t[i]);
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int p = 1; p <= m; p++) {
        for (int i = 0; i < sta[p].size(); i++) 
            for (int j = i + 1; j < sta[p].size(); j++) {
                int u = sta[p][i].first, v = sta[p][j].first, t1 = sta[p][i].second, t2 = sta[p][j].second;
                f[u][v] = f[v][u] = t1 + t2;
            }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--) {
        int u, v; cin >> u >> v;
        int ans = inf;
        for (auto l1 : sta[u])
            for (auto l2 : sta[v]) 
                ans = min(ans, f[l1.first][l2.first] + w[u] + w[v] + l1.second + l2.second);
        cout << ans << '\n';
    }
    return 0;
}
/*
g++ subway.cpp -o subway -std=c++14 -O2 -Wall -Wextra -fsanitize=undefined,address && ./subway
./subway < subway1.in > subway.out && diff subway1.ans subway.out

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


32 17
*/