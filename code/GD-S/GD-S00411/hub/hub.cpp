#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 1000005

int cid, t, n, k; vector<int> e[MAXN]; int d[MAXN];

void dfs(int x, int f, int dep){d[x] = min(d[x], dep); for (auto v: e[x]) if (v ^ f) dfs(v, x, dep+1);}

namespace sol1{  // n <= 10
    bool vis[MAXN], gg[MAXN];
    void dfs2(int x, int f){vis[x] = 1; for (auto v: e[x]) if (v != f && gg[v] && !vis[v]) dfs2(v, x);}
    void sol(){
        int ans(0x3f3f3f3f);
        for (int i(1); i<(1<<n); ++i) if (__builtin_popcount(i) == k){
            for (int j(1); j<=n; ++j) gg[j] = i>>(j-1)&1; fill(vis+1, vis+n+1, 0); int ct(0);
            for (int j(1); j<=n; ++j) if (gg[j] && !vis[j]) dfs2(j, 0), ++ct; if (ct > 2) continue;
            fill(d+1, d+n+1, 0x3f3f3f3f); for (int j(0); j<n; ++j) if (i>>j&1) dfs(j+1, 0, 0);
            // for (int i(1); i<=n; ++i) cerr << d[i] << ' '; cerr << '\n';
            ans = min(ans, *max_element(d+1, d+n+1));
        }
        cout << ans << '\n';
    }
}
namespace sol2{  // k = 2
    int ct;
    int dfs(int x, int f, int v){
        int rx(1e9), ry(0);
        for (auto y: e[x]) if (y ^ f){
            int val(dfs(y, x, v)); if (val < 0) rx = min(rx, -val+1); else ry = max(ry, val+1);
        }
        // cerr << x << ' ' << rx << ' ' << ry << ' ' << (rx+ry-1 <= v || ry < v) << '\n';
        if (rx+ry-1 <= v) return -rx; if (ry < v && x != 1) return ry; ++ct; return -1;
    }
    bool chk(int x){
        ct = 0; dfs(1, 0, x); return ct <= 2;
    }
    void sol(){
        int l(0), r(n), mid;
        while (l < r){
            mid = (l+r)>>1; if (chk(mid)) r = mid; else l = mid+1;
        }
        cout << l << '\n';
        // cerr << chk(2);
    }
}

signed main(){
    freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (cin >> cid >> t; t; --t){
        cin >> n >> k; for (int i(1), u, v; i<n; ++i) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
        // if (k == 2) sol2::sol(); else if (n <= 10) sol1::sol();
        if (k == 2) sol2::sol(); else sol1::sol();
        for (int i(1); i<=n; ++i) e[i].clear();
    }

    return 0;
}