#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; ++i)
#define _req(i, x, y) for(int i = x; i >= y; --i)
#define fi first
#define se second
#define pb push_back
#define mst(f, i) memset(f, i, sizeof f)
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
namespace fastio{
    template<typename T> inline void read(T &t){
        T x = 0, f = 1;
        char c = getchar();
        while(!isdigit(c)){
            if(c == '-') f = -f;
            c = getchar();
        }
        while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
        t = x * f;
    }
    template<typename T, typename ... Args> inline void read(T &t, Args &...args){
        read(t), read(args...);
    }
    void write(int x){printf("%d", x);}
    void writes(int x){printf("%d ", x);}
    void writeln(int x){printf("%d\n", x);}
    void write(ll x){printf("%lld", x);}
    void writes(ll x){printf("%lld ", x);}
    void writeln(ll x){printf("%lld\n", x);}
}
using namespace fastio;
#define multitest() int T; read(T); _rep(tCase, 1, T)
const int N = 1e6 + 5, inf = 0x3f3f3f3f;
int tid, n, k, x, y, len, d, p[N];
vector<int> G[N];
int w[N], curf[N][2];
int f[N][2], g[N];
int dep[N], pre[N];
void dfs(int u, int fa, int &x){
    dep[u] = dep[fa] + 1, pre[u] = fa;
    if(dep[u] > dep[x]) x = u;
    for(auto &v : G[u]) if(v != fa) dfs(v, u, x);
}
void dfs2(int u, int fa){
    f[u][0] = f[u][1] = 0;
    for(auto &v : G[u]) if(v != fa){
        dfs2(v, u);
        int t = f[v][0] + 1;
        if(t > f[u][0]) f[u][1] = f[u][0], f[u][0] = t;
        else if(t > f[u][1]) f[u][1] = t;
    }
}
void dfs3(int u, int fa){
    g[u] = f[u][0] >= d;
    for(auto &v : G[u]) if(v != fa){
        dfs3(v, u), g[u] += g[v];
    }
}
vector<PII> h[N][2];
vector<int> vl[N], vr[N];
void dfs4(int u, int fa, int t, int curd, int col, int op){
    if(t > d) return;
    if(g[u]) h[col][op].pb({curd, g[u]});
    for(auto &v : G[u]) if(v != fa){
        int nt = max(t, f[u][0] == f[v][0] + 1 ? f[u][1] : f[u][0]) + 1;
        dfs4(v, u, nt, curd + 1, col, op);
    }
}
int minc;
void dfs5(int u, int fa, int t, int cur, int lst){
    minc = min(minc, cur + max(1, g[u]) - lst);
    for(auto &v : G[u]) if(v != fa){
        int now = f[v][0] + 1 == f[u][0] ? f[u][1] : f[u][0];
        int nlst = now >= d ? g[v] : lst;
        dfs5(v, u, t + 1, cur, nlst);
    } 
}
int top; PII st[N];
bool check(int mid){
    d = mid, dfs3(x, 0);
    int cur = 0;
    _rep(i, 1, len){
        int u = p[i], now = 1;
        for(auto &v : G[u]) if(v != p[i - 1] && v != p[i + 1]) now += g[v];
        h[i][0].pb({0, now + cur});
        if(i - 1 >= d) cur += now;
        if(i - 1 < d){
            for(auto &v : G[u]) if(v != p[i - 1] && v != p[i + 1]){
                int t = max(i - 1, f[v][0] + t == curf[i][0] ? curf[i][1] : curf[i][0]) + 1;
                dfs4(v, u, t, 1, i, 0);
            }
        }
    }
    cur = 0;
    _req(i, len, 1){
        int u = p[i], now = 1;
        for(auto &v : G[u]) if(v != p[i - 1] && v != p[i + 1]) now += g[v];
        h[i][1].pb({0, now + cur});
        if(len - i >= d) cur += now;
        else{
            for(auto &v : G[u]) if(v != p[i - 1] && v != p[i + 1]){
                int t = max(len - i, f[v][0] + t == curf[i][0] ? curf[i][1] : curf[i][0]) + 1;
                dfs4(v, u, t, 1, i, 1);
            }
        }
    }
    bool ok = 0;
    _rep(i, 1, len){
        for(auto &[j, t] : h[i][0]) if(t <= k && len - i + j <= d) ok = 1;
        for(auto &[j, t] : h[i][1]) if(t <= k && i - 1 + j <= d) ok = 1;
    }
    _rep(i, 2, len - 1){
        if(curf[i][0] <= d) continue;
        int u = p[i], t = 0, minx = inf, tot = 0;
        for(auto &v : G[u]) if(v != p[i - 1] && v != p[i + 1]) tot += g[v];
        for(auto &v : G[u]) if(v != p[i - 1] && v != p[i + 1]){
            int now = f[v][0] + 1 == curf[i][0] ? curf[i][1] : curf[i][0];
            minc = inf;
            int lst = now >= d ? g[v] : tot;
            dfs5(v, u, 1, tot, lst);
            minx = min(minx, minc);
            // if(mid == 2 && u == 2){
            //     debug("tot:%d lst:%d v:%d\n", tot, lst, v);
            // }
            // if(mid == 2 && u == 2) debug("v:%d minc:%d\n", v, minc);
        }
        int cur = minx + h[i - 1][0][0].se + h[i + 1][1][0].se + 1;
        if(cur <= k){
            // if(mid == 2){
            //     debug("u:%d minc:%d\n", u, minx);
            // }
            ok = 1;
        }
    }
    // if(mid == 1) debug("%d\n", ok);
    st[top = 1] = {len + 1, inf};
    _req(i, len, 1){
        for(auto &[l, kl] : h[i][0]){
            int cl = 1, cr = top, res = 0;
            while(cl <= cr){
                int mid = cl + cr >> 1;
                if(st[mid].se > d + i - l) res = st[mid].fi, cl = mid + 1;
                else cr = mid - 1;
            }
            vl[res - 1].pb(kl);
        }
        while(top && w[i] + i >= st[top].se) top--;
        st[++top] = {i, w[i] + i};
    }
    st[top = 1] = {0, inf};
    _rep(i, 1, len){
        for(auto &[r, kr] : h[i][1]){
            int cl = 1, cr = top, res = 0;
            while(cl <= cr){
                int mid = cl + cr >> 1;
                if(st[mid].se > d - i - r) res = st[mid].fi, cl = mid + 1;
                else cr = mid - 1;
            }
            vr[res + 1].pb(kr);
        }
        while(top && w[i] - i >= st[top].se) top--;
        st[++top] = {i, w[i] - i};
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    for(auto &i : vr[1]) pq.push(i);
    _rep(i, 1, len){
        if(i < len){
            for(auto &j : vr[i + 1]) pq.push(j);
        }
        for(auto &j : vl[i]) if(pq.size() && pq.top() + j <= k){
            ok = 1;
        }
    }
    _rep(i, 0, len + 1){
        h[i][0].clear(), h[i][1].clear();
        vl[i].clear(), vr[i].clear();
    }
    top = 0;
    return ok;
}
void init(){
    x = y = len = 0;
    dfs(1, 0, x), dfs(x, 0, y);
    for(int i = y; i; i = pre[i]) p[++len] = i;
    reverse(p + 1, p + 1 + len), p[0] = p[len + 1] = 0;
    // debug("x:%d y:%d\n", x, y);
    // _rep(i, 1, len) debug("%d ", p[i]); debug("\n");
    dfs2(x, 0);
    _rep(i, 1, len){
        int u = p[i];
        for(auto &v : G[u]) if(v != p[i - 1] && v != p[i + 1]){
            int t = f[v][0] + 1;
            if(t > curf[i][0]) curf[i][1] = curf[i][0], curf[i][0] = t;
            else if(t > curf[i][1]) curf[i][1] = t;
        }
        w[i] = curf[i][0];
    }
}
void clr(){
    _rep(i, 0, n + 1) G[i].clear(), f[i][0] = f[i][1] = g[i] = dep[i] = pre[i] = p[i] = 0, curf[i][0] = curf[i][1] = w[i] = 0;
    n = k = x = y = len = d = 0;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    read(tid);
    multitest(){
        read(n, k);
        // if(tCase == 389) debug("%d %d\n", n, k);
        _rep(i, 2, n){
            int u, v; read(u, v);
            G[u].pb(v), G[v].pb(u);
        // if(tCase == 389) debug("%d %d\n", u, v);
        }
        init();
        int l = 0, r = n - 1, res = n;
        while(l <= r){
            int mid = l + r >> 1;
            if(check(mid)) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        writeln(res);
        clr();
    }
    return 0;
}