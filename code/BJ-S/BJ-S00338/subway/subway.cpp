#include <iostream>
#include <vector>
#include <cstdio>
#define int long long
using namespace std;
int c, n, m, d, q;
int w[500010];
int F[510][510];
struct S { int id, tm; };
vector<S> ss[500010];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            ss[a].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) F[i][j] = 0;
            else F[i][j] = 4e18;
        }
    }
    for(int i = 1; i <= m; i++) {
        int t = ss[i].size();
        for(int j = 0; j < t; j++) {
            int u = ss[i][j].id, t1 = ss[i][j].tm;
            for(int k = j + 1; k < t; k++) {
                int v = ss[i][k].id, t2 = ss[i][k].tm;
                F[u][v] = F[v][u] = min(F[u][v], t1 + t2);
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            if(k == i) continue;
            for(int j = 1; j <= n; j++) {
                if(j == i || k == j) continue;
                F[i][j] = min(F[i][j], F[i][k] + F[k][j]);
            }
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        int ans = 4e18, t1 = ss[x].size(), t2 = ss[y].size();
        for(int i = 0; i < t1; i++) {
            for(int j = 0; j < t2; j++) {
                ans = min(ans, F[ss[x][i].id][ss[y][j].id] + ss[x][i].tm + ss[y][j].tm);
            }
        }
        ans += w[x], ans += w[y];
        cout << ans << '\n';
    }
    return 0;
}