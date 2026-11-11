#include<bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
#define rg register
#define vi std::vector<int>
#define pb push_back
#define us(n) (1LL << n)
#define L(i, a, b) for (rg int i = (a); i <= (b); i++)
#define R(i, a, b) for (rg int i = (a); i >= (b); i--)
#define rep(i, a) for (rg auto i : (a))
const int N = 3e5 + 5, M = 21, p = 1e9 + 7, inf = 8e18;
namespace xyx{
    int n, K, fa[N][M], dep[N], vis[N]; vi g[N];
    il void dfs(int u, int c){
        fa[u][0] = c, dep[u] = dep[c] + 1;
        rep(v, g[u]){
            if (v == c) continue;
            dfs(v, u);
        }
    }
    il int lca(int u, int v){
        if (dep[u] < dep[v]) std::swap(u, v);
        R(i, 20, 0) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        if (u == v) return u;
        R(i, 20, 0) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
        return fa[u][0];
    }
    int st[N], W[1005][1005];
    #define dis(u, v) (dep[u] + dep[v] - 2 * dep[W[u][v]])
    il void cal(int u, int c){
        if (st[u]) return ; st[u] = c;
        rep(v, g[u]) if (!st[v] && vis[v]) cal(v, c);
    }
    #define dist(u, v) (dep[u] + dep[v] - 2 * dep[lca(u, v)])
    il void slv(){ int sid, t = 1; std::cin >> sid >> t; while(t--){
        std::cin >> n >> K; L(i, 1, n) g[i].clear();
        L(i, 1, n - 1){
            int u, v; std::cin >> u >> v;
            g[u].pb(v), g[v].pb(u);
        }
        dfs(1, 0); L(j, 1, 20) L(i, 1, n) fa[i][j] = fa[fa[i][j - 1]][j - 1];
        if (n <= 10){
            int sna = inf / 2;
            L(i, 0, us(n) - 1){
                if (__builtin_popcountll(i) != K) continue;
                L(j, 1, n) if (i >> (j - 1) & 1) vis[j] = 1, st[j] = 0; else vis[j] = st[j] = 0;
                int id = 0; L(j, 1, n) if (vis[j] && !st[j]) id++, cal(j, id);
                if (id != 2) continue;
                int ans = -inf / 2;
                L(j, 1, n) if (!vis[j]){
                    int ret = inf / 2;
                    L(k, 1, n) if (vis[k]) ret = std::min(ret, dist(k, j));
                    ans = std::max(ans, ret);
                }
                sna = std::min(sna, ans);
            }
            std::cout << sna << "\n";
            continue;
        }
        if (K == 2 && n <= 1000){
            L(i, 1, n) L(j, 1, n) W[i][j] = lca(i, j); int sna = inf / 2;
            L(i, 1, n){
                L(j, 1, n) st[j] = 1; rep(j, g[i]) st[j] = 0;
                L(j, 1, n) if (st[j]){
                    int ret = -inf / 2;
                    L(k, 1, n) if (k != i && k != j) ret = std::max(ret, std::min(dis(k, i), dis(k, j)));
                    sna = std::min(sna, ret);
                }
            }
            std::cout << sna << "\n";
            continue;
        }
        std::cout << (n - 1 - 1) / (2 * K) + 1 << "\n";
    }
    }
} signed main(){
    freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    return xyx::slv(), 0;
}
/*
g++ hub.cpp -o hub.exe -std=c++14 -O2 -Wall -Wextra -Wshadow "-Wl,--stack=512000000";if($?){./hub}
*/