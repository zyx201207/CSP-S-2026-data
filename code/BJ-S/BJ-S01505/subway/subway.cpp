#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
const ll INF = 1e18;
inline int read(){
    int s = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9'){
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9'){
        s = (s << 1) + (s << 3) + c - '0';
        c = getchar();
    }
    return s * f;
}
int lec, n, m, d, Q;
int w[MAXN];
vector<pii > vec[MAXN];
ll dis[505][505];
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    lec = read(), n = read(), m = read(), d = read(), Q = read();
    for (int i = 1; i <= m; i++){
        w[i] = read();
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j) dis[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++){
        int k = read();
        while (k--){
            int aa = read(), tt = read();
            if (!vec[aa].empty()){
                for (auto kv : vec[aa]){
                    if (1ll * kv.se + 1ll * tt < dis[kv.fi][i]){
                        dis[kv.fi][i] = 1ll * kv.se + 1ll * tt;
                        dis[i][kv.fi] = 1ll * kv.se + 1ll * tt;
                    }
                }
            }
            vec[aa].push_back({i, tt});
        }
    }
    for (int k = 1; k <= n; k++){
        for (int u = 1; u <= n; u++){
            for (int v = 1; v <= n; v++){
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }
    while (Q--){
        int x, y;
        x = read(), y = read();
        ll ans = INF;
        for (auto l : vec[x]){
            for (auto r : vec[y]){
                ans = min(ans, dis[l.fi][r.fi] + 1ll * l.se + 1ll * r.se);
            }
        }
        ans += 1ll * w[x] + 1ll * w[y];
        printf("%lld\n", ans);
    }
    return 0;
}
