#include <bits/stdc++.h>
using namespace std;

namespace xieheng24 {
    #define endl '\n'
    #define rep(i, a, b) for (int i = (a); i <= (b); ++i)
    #define _rep(i, a, b) for (int i = (a); i < (b); ++i)
    #define per(i, a, b) for (int i = (a); i >= (b); --i)
    typedef long long ll;
    typedef unsigned long long ull;

    template<typename T, typename T1> 
    __inline void chkmax(T& x, T1 y) {
        if (y > x) x = y;
    }

    template<typename T, typename T2>
    __inline void chkmin(T& x, T2 y) {
        if (y < x) x = y;
    }

    constexpr int N = 35, K = 20;
    int c, T;
    vector<int> g[N];
    int n, k;
    int p[N];
    int f[N][N];
    
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void solve() {
        cin >> n >> k;
        rep(i, 1, n) g[i].clear();
        memset(f, 0x3f ,sizeof f);
        rep(i, 1, n - 1) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            f[u][v] = f[v][u] = 1;
        }
        rep(i, 1, n) f[i][i] = 0;
        rep(k, 1, n) {
            rep(i, 1, n) {
                rep(j, 1, n) {
                    chkmin(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        ll res = 1e18;
        _rep(S, 1, 1 << n) {
            if (__builtin_popcount(S) != k) continue; 
            rep(i, 1,n  ) p[i] = i;
            rep(i, 1, n) {
                if (S >> (i - 1) & 1) {
                    for (auto ver : g[i]) {
                        if (S >> (ver - 1) & 1) {
                            int x = find(i), y = find(ver);
                            if (x != y) p[x] = y;
                        }
                    }
                }
            } 
            vector<int> v;
            rep(i, 1,n ) if (S >> (i - 1) & 1) v.push_back(find(i));
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            if (v.size() > 2) continue;
            ll t = 0;
            rep(i ,1, n) {
                if (S >> (i - 1) & 1) continue;
                ll s = 1e18;
                rep(j, 1,n ) {
                    if (S >> (j - 1) & 1) {
                        chkmin(s, f[i][j]);
                    }
                }
                chkmax(t, s);
            }
            // cout << S << " " << t << endl;
            chkmin(res, t);
        }
        cout << res << endl;
    }

    int main() {
        cin >> c >> T;
        while (T-- ) {
            solve();
        }

        return 0;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    return xieheng24::main();
}