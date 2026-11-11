#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define il inline
#define pii pair<int, int>
#define x first
#define y second
#define debug() puts("----------")
#define rd read()
#define gc getchar()
#define U(i, x, y) for(re int (i) = (x); (i) <= (y); ++ (i))
#define UU(i, x, y) for(re int (i) = (x); (i) < (y); ++ (i))
#define D(i, x, y) for(re int (i) = (x); (i) >= (y); -- (i))
#define DD(i, x, y) for(re int (i) = (x); (i) > (y); -- (i))

namespace yzqwq{
    il int read(){
        int x = 0, f = 1; char ch = gc;
        while(ch < '0' || ch > '9'){
            if(ch == '-') f = -1;
            ch = gc;
        }
        while(ch >= '0' && ch <= '9'){
            x = (x << 1) + (x << 3) + (ch ^ 48);
            ch = gc;
        }
        return x * f;
    }
    il int qmi(int a, int b, int mod){
        int res = 1;
        while(b){
            if(b & 1) res = res * a % mod;
            a = a * a % mod, b >>= 1;
        }
        return res;
    }
    il int gcd(int a, int b){
        if(!b) return a;
        return gcd(b, a % b);
    }
    mt19937 rnd(time(0));
}
using namespace yzqwq;

bool f1;
const int N = 1e6 + 10;
int n, k;
vector<pii> e[N];
int bid;
pii E[N];
int f[N], g[N], h[N];

il void dfs1(int u, int fa){
    f[u] = 0;
    for(auto [v, id]: e[u]) if(v != fa && id != bid){
        dfs1(v, u);
        f[u] = max(f[u], f[v] + 1);
    }
    return ;
}
il void dfs2(int u, int fa){
    int mx1 = g[u], i1 = u;
    int mx2 = 0, i2 = 0;
    for(auto [v, id]: e[u]) if(v != fa && id != bid){
        if(f[v] + 1 > mx1){
            mx2 = mx1, i2 = i1;
            mx1 = f[v] + 1, i1 = v;
        }
        else if(f[v] + 1 > mx2){
            mx2 = f[v] + 1, i2 = v;
        }
    }
    for(auto [v, id]: e[u]) if(v != fa && id != bid){
        if(v == i1){
            g[v] = mx2 + 1;
        }
        else{
            g[v] = mx1 + 1;
        }
        dfs2(v, u);
    }
    return ;
}
il void dfs3(int u, int fa){
    h[u] = 0;
    for(auto [v, id]: e[u]) if(v != fa && id != bid){
        dfs3(v, u);
        h[u] = max(h[u], h[v] + 1);
    }
    return ;
}

il bool chk(int mid, bool ffff){
    {
        bid = 0;
        dfs1(1, 0), g[1] = 0, dfs2(1, 0);
        int rt = 0;
        U(i, 1, n) if(!rt || max(f[i], g[i]) < max(f[rt], g[rt])) rt = i;
        dfs3(rt, 0);
        int sum = 0;
        U(i, 1, n) sum += (h[i] >= mid);
        sum = max(1ll, sum);
        if(sum <= k) return true;
    }
    if(ffff == 1){
        int lim = 20;
        while(lim --){
            bid = rnd() % (n - 1) + 1;
         int u = E[bid].x, v = E[bid].y;

        int s = 0;
        U(i, 1, n) f[i] = g[i] = 1e9 + 7;
        dfs1(u, 0), g[u] = 0, dfs2(u, 0);
        {
            int rt = 0;
            U(i, 1, n) if(!rt || max(f[i], g[i]) < max(f[rt], g[rt])) rt = i;
            dfs3(rt, 0);
        }
        int s1 = 0;
        U(i, 1, n) if(f[i] < 1e9) s1 += (h[i] >= mid);
        s1 = max(1ll, s1);

        U(i, 1, n) f[i] = g[i] = 1e9 + 7;
        dfs1(v, 0), g[v] = 0, dfs2(v, 0);
        {
            int rt = 0;
            U(i, 1, n) if(!rt || max(f[i], g[i]) < max(f[rt], g[rt])) rt = i;
            dfs3(rt, 0);
        }
        int s2 = 0;
        U(i, 1, n) if(f[i] < 1e9) s2 += (h[i] >= mid);
        s2 = max(1ll, s2);

        if(s1 + s2 <= k) return true;                 
        }
        return false;
    }
    for(bid = 1; bid < n; ++ bid){
        int u = E[bid].x, v = E[bid].y;

        int s = 0;
        U(i, 1, n) f[i] = g[i] = 1e9 + 7;
        dfs1(u, 0), g[u] = 0, dfs2(u, 0);
        {
            int rt = 0;
            U(i, 1, n) if(!rt || max(f[i], g[i]) < max(f[rt], g[rt])) rt = i;
            dfs3(rt, 0);
        }
        int s1 = 0;
        U(i, 1, n) if(f[i] < 1e9) s1 += (h[i] >= mid);
        s1 = max(1ll, s1);

        U(i, 1, n) f[i] = g[i] = 1e9 + 7;
        dfs1(v, 0), g[v] = 0, dfs2(v, 0);
        {
            int rt = 0;
            U(i, 1, n) if(!rt || max(f[i], g[i]) < max(f[rt], g[rt])) rt = i;
            dfs3(rt, 0);
        }
        int s2 = 0;
        U(i, 1, n) if(f[i] < 1e9) s2 += (h[i] >= mid);
        s2 = max(1ll, s2);

        if(s1 + s2 <= k) return true;        
    }
    return false;
}

il void solve(bool flg = 0){
    n = rd, k = rd;
    U(i, 0, n + 1){
        e[i].clear();
    }
    UU(i, 1, n){
        int u = rd, v = rd;
        E[i] = {u, v};
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }
    // cout<<chk(0);return ;
    int l = 0, r = n, ans = -1;
    while(l <= r){
        int mid = l + r >> 1;
        if(chk(mid, flg)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << "\n";
    return ;
}

il bool chk1(int mid){
    {
        bid = 0;
        dfs1(1, 0), g[1] = 0, dfs2(1, 0);
        int rt = 0;
        U(i, 1, n) if(!rt || max(f[i], g[i]) < max(f[rt], g[rt])) rt = i;
        dfs3(rt, 0);
        int sum = 0;
        U(i, 1, n) sum += (h[i] >= mid);
        sum = max(1ll, sum);
        if(sum <= k) return true;
    }
    return false;
}
int F[N][20], dep[N];
il void dfs0(int u, int fa){
    dep[u] = dep[fa] + 1;
    F[u][0] = fa;
    UU(i, 1, 20) F[u][i] = F[F[u][i - 1]][i - 1];
    for(auto [v, id]: e[u]) if(v != fa){
        dfs0(v, u);
    } 
    return ;
}
il int lca(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    D(i, 19, 0) if(dep[F[x][i]] >= dep[y]) x = F[x][i];
    if(x == y) return x;
    D(i, 19, 0) if(F[x][i] != F[y][i]) x = F[x][i], y = F[y][i];
    return F[x][0];
}
il int dis(int x, int y){ return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
il pii merge(pii x, pii y){
    pii z = x;
    int dis11 = dis(x.x, y.x);
    int dis12 = dis(x.x, y.y);
    int dis21 = dis(x.y, y.x);
    int dis22 = dis(x.y, y.y);       
    int mx = max({dis(x.x, x.y), dis(y.x, y.y), dis11, dis12, dis21, dis22});    
        if(mx == dis11) z = {x.x,y.x};
        else if(mx == dis12) z = {x.x, y.y};
        else if(mx == dis21) z = {x.y, y.x};
        else if(mx == dis22) z = {x.y, y.y};
        else if(mx == dis(y.x, y.y)) z = y;  
    return z;  
}
pii harmis[N];
il void Dfs(int u, int fa){
    harmis[u] = {u, u};
    for(auto [v, id]: e[u]) if(v != fa){
        Dfs(v, u);
        int dis11 = dis(harmis[u].x, harmis[v].x);
        int dis12 = dis(harmis[u].x, harmis[v].y);
        int dis21 = dis(harmis[u].y, harmis[v].x);
        int dis22 = dis(harmis[u].y, harmis[v].y);       
        int mx = max({dis(harmis[u].x, harmis[u].y), dis(harmis[v].x, harmis[v].y), dis11, dis12, dis21, dis22});
        if(mx == dis11) harmis[u] = {harmis[u].x, harmis[v].x};
        else if(mx == dis12) harmis[u] = {harmis[u].x, harmis[v].y};
        else if(mx == dis21) harmis[u] = {harmis[u].y, harmis[v].x};
        else if(mx == dis22) harmis[u] = {harmis[u].y, harmis[v].y};
        else if(mx == dis(harmis[v].x, harmis[v].y)) harmis[u] = harmis[v];
    }
    return ;
}
int ffmin;
pii zj;
il void dfsc(int u, int fa){
    if(fa){
        int spd = max((dis(harmis[u].x, harmis[u].y) + 1) / 2, (dis(zj.x, zj.y) + 1) / 2);
        ffmin = min(ffmin, spd);
    }
    vector<pii> pre, suf;
    pre.clear(), suf.clear();
    if(!e[u].empty()){
        if(e[u][0].x == fa) pre.emplace_back(u, u);
		else pre.emplace_back(merge({u, u}, harmis[e[u][0].x]));
        U(i, 1, (int)(e[u].size()) - 1){
            if(e[u][i].x == fa) pre.emplace_back(pre.back());
            else pre.emplace_back(merge(harmis[e[u][i].x], pre.back()));
        }
        if(e[u].back().x == fa) suf.emplace_back(u, u);
        else suf.emplace_back(merge({u, u}, harmis[e[u].back().x]));
        D(i, (int)(e[u].size()) - 2, 0){
            if(e[u][i].x == fa) suf.emplace_back(suf.back());
            else suf.emplace_back(merge(harmis[e[u][i].x], suf.back()));
        }
        reverse(suf.begin(), suf.end());
    }
    U(i, 0, (int)(e[u].size()) - 1) if(e[u][i].x != fa){
        int v = e[u][i].x;
        pii zj_ = zj;
        zj = merge(zj, {u, u});
        if(i >= 1) zj = merge(zj, pre[i - 1]);
        if(i + 1 < (int)(e[u].size())) zj = merge(zj, suf[i + 1]);
        dfsc(v, u);
        zj = zj_;
    }
    return ;
}
il void solve1(){
    n = rd, k = rd;
    U(i, 0, n + 1){
        e[i].clear();
    }
    UU(i, 1, n){
        int u = rd, v = rd;
        E[i] = {u, v};
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }
    int l = 0, r = n, ans = -1;
    while(l <= r){
        int mid = l + r >> 1;
        if(chk1(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    ffmin = 1e18;
    dfs0(1, 0);
    Dfs(1, 0);
    zj = {1, 1};
    dfsc(1, 0);
    cout << min(ans, ffmin) << "\n";
    return ;
}
bool f2;

signed main(){
    // cout<<(&f1-&f2)/1024/1024;
    // return 0;
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c = rd, t = rd; while(t --){
       if(c <= 10) solve();
       else if(c >= 11 && c <= 12) solve1();
       else solve(1);
    }
    return 0;
}
