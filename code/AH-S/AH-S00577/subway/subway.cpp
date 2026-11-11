#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll Read() {
    ll x = 0; int sig = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') sig = -1; c = getchar(); }
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    return x * sig;
}
inline void Write(ll x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) Write(x / 10);
    putchar((x % 10) ^ 48);
}
const int N = 505, M = 500005;
const ll inf = 1e18;
int n, m, d, q;
ll w[M], dis[N][N];
vector<pair<int, ll> > vec[M], line[N];
int main() {
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
    int c = Read(), i, j, k; n = Read(), m = Read(), d = Read(), q = Read();
    for(i = 1; i <= m; i++) w[i] = Read();
    for(i = 1; i <= n; i++) {
        k = Read(); int a; ll t;
        while(k--) {
            a = Read(), t = Read();
            line[i].emplace_back(a, t), vec[a].emplace_back(i, t);
        }
    }
    for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) dis[i][j] = i == j ? 0ll : inf;
    for(i = 1; i <= n; i++) for(auto p : line[i]) {
        int x = p.first;
        for(auto v : vec[x]) {
            j = v.first;
            if(j != i) dis[i][j] = dis[j][i] = min(dis[i][j], p.second + v.second);
        }
    }
    for(k = 1; k <= n; k++) for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
    }
    while(q--) {
        int u = Read(), v = Read(); ll ans = inf;
        for(auto x : vec[u]) for(auto y : vec[v]) ans = min(ans, x.second + y.second + dis[x.first][y.first]);
        Write(ans + w[u] + w[v]), putchar('\n');
    }
}