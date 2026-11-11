#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c)) f = (c == '-' ? -1 : f), c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, w[M], dis[N][N];
vector<PII> hs[M];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1; i <= m; i++) w[i] = read();
    for(int i = 1, k, x, y; i <= n; i++) {
        k = read();
        for(int j = 1; j <= k; j++) x = read(), y = read(), hs[x].push_back({i, y});
    }
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= n; i++) dis[i][i] = 0;
    for(int i = 1; i <= m; i++) {
        for(auto [a1, b1] : hs[i]) {
            for(auto [a2, b2] : hs[i]) {
                if(a1 <= a2) continue;
                dis[a1][a2] = min(dis[a1][a2], b1 + b2);
                dis[a2][a1] = min(dis[a2][a1], b1 + b2);
            }
        }
    }
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while(q--) {
        int x = read(), y = read(), ans = 1e18;
        for(auto [a1, b1] : hs[x]) for(auto [a2, b2] : hs[y]) ans = min(ans, b1 + b2 + dis[a1][a2]);
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}
