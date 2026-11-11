#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int MAXN = 1e6 + 5;
int cid, n, k, id;
struct Edge{ int to, nxt; }e[MAXN << 1];
int head[MAXN], cur;
void Add(int u, int v){ e[++cur] = {v, head[u]}; head[u] = cur; }
// int f[MAXN], g[MAXN][MAXN][MAXN], h[MAXN][MAXN][MAXN];
int dep[MAXN], mxdep[MAXN], dis[MAXN];
bool vis[MAXN];
pii eg[MAXN];

void dfs(int u, int fa){
    mxdep[u] = dep[u] = dep[fa] + 1;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == fa) continue;
        dfs(v, u); mxdep[u] = max(mxdep[u], mxdep[v]);
    }
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == fa) continue;
        // for(int i = )
    }
}

void dfs1(int u, int fa, int t, int rt){
    mxdep[u] = dep[u] = dep[fa] + 1;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == fa) continue;
        dfs1(v, u, t, rt); mxdep[u] = max(mxdep[u], mxdep[v]);
    }
    if(mxdep[u] - dep[u] == t && u != rt) id = u;
}

bool check(int x){
    // id = 0; dfs1(1, 0, x);
    // if(!id) return true;
    // int u = id; id = 0; dfs1(u, 0, x);
    // if(!id) return true;
    for(int u = 1; u <= n; ++u){
        id = 0; dfs1(u, 0, x, u);
        if(!id) return true;
        for(int i = 1; i <= n; ++i){
            vis[i] = false;
            if(dep[i] - 1 <= x) vis[i] = true;
        }
        dfs1(id, 0, id, id);
        for(int i = 1; i <= n; ++i){
            if(dep[i] - 1 <= x) vis[i] = true;
        }
        bool flag = false;
        for(int i = 1; i <= n; ++i){
            if(!vis[i]) flag = true;
        }
        if(!flag) return true;
    }
    return false;
}

void solve(){
    cin >> n >> k; cur = 0;
    for(int i = 1; i <= n; ++i){
        head[i] = 0;
    }
    for(int i = 1, u, v; i < n; ++i){
        cin >> u >> v; Add(u, v), Add(v, u);
        eg[i] = {u, v};
    }
    if(n == k){
        cout << "0\n";
        return;
    }
    if(cid == 1 || cid == 2 || cid == 3){
        int mn = n + 1;
        for(int i = 0; i < (1 << n); ++i){
            if(__builtin_popcount(i) != k) continue;
            for(int j = 1; j <= n; ++j) dis[j] = n + 1;
            int tmp = k;
            for(int j = 1; j < n; ++j){
                int u = eg[j].fi, v = eg[j].se;
                if((i >> (u - 1) & 1) && (i >> (v - 1) & 1)) tmp--;
            }
            if(tmp > 2) continue;
            for(int j = 1; j <= n; ++j) if(i >> (j - 1) & 1){
                dfs1(j, 0, 0, 0);
                for(int p = 1; p <= n; ++p) dis[p] = min(dis[p], dep[p] - 1);
            }
            int mx = 0;
            // if(i == 9){
            //     for(int j = 1; j <= n; ++j) cout << dis[j] << ' '; cout << '\n';
            // }
            for(int j = 1; j <= n; ++j) mx = max(mx, dis[j]);
            // if(mx == 1){
            //     cout << i << '\n';
            //     for(int j = 1; j <= n; ++j) if(i >> (j - 1) & 1) cout << j << ' '; cout << '\n';
            //     for(int j = 1; j <= n; ++j) cout << dis[j] << ' '; cout << '\n';
            // }
            mn = min(mn, mx);
        }
        cout << mn << '\n';
        return;
    }
    if(cid == 13 || cid == 14){
        int m = n / 2;
        for(int i = 1; i <= m; ++i){
            bool flag = false;
            if(i + k - 1 >= m) flag = true;
            else{
                int x = i + k - 2 + (i - 1) * 2 + 1;
                if(m - x + 1 <= i) flag = true;
            }
            if(flag){
                cout << i << '\n';
                return;
            }
        }
    }
    if(cid == 0 || cid == 7 || cid == 11 || cid == 12){
        int l = 1, r = n, ans = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
}

signed main(){
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T; cin >> cid >> T; while(T--) solve();

    return 0;
}