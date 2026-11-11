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
const int N = 1000005;
int n, k, cntdfn, dep[N], anc[20][N], lowbit[N];
pair<int, int> f[N], g[N]; 
// maxd < D : (-1, maxd)
// maxd >= D : (u, |S|)
vector<int> e[N];
int D, ans;
void Dfs(int u, int _fa) {
    dep[u] = dep[_fa] + 1, anc[0][u] = _fa;
    for(auto v : e[u]) if(v != _fa) Dfs(v, u);
}
// void Dfs2(int u, int _fa) {
//     int t = 0; vector<int> vec = e[u];
//     for(auto v : vec) if(v != _fa) g[v] = max(g[v], t + 1), t = max(t, h[v]);
//     reverse(vec.begin(), vec.end()), t = g[u];
//     for(auto v : vec) if(v != _fa) g[v] = max(g[v], t + 1), t = max(t, h[v]), Dfs2(v, u);
// }
inline int Kth(int u, int d) {
    if(d <= 0) return u;
    while(d) u = anc[lowbit[d]][u], d ^= d & -d;
    return u;
}
inline int LCA(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    v = Kth(v, dep[v] - dep[u]); if(u == v) return u;
    for(int i = 19; i >= 0; i--) if(anc[i][u] != anc[i][v]) u = anc[i][u], v = anc[i][v];
    return anc[0][u];
}
inline void Move(int &u, int &x, int v, int d) {
    int l = LCA(u, v), t = dep[u] + dep[v] - dep[l] * 2; x += max(t - d, 0);
    if(dep[v] - dep[l] >= d) u = Kth(v, d);
    else u = Kth(u, t - d);
}
inline int Dis(int u, int v) { return dep[u] + dep[v] - dep[LCA(u, v)] * 2; }
pair<int, int> Add(int u, pair<int, int> x, pair<int, int> y) {
    if(x.first > y.first) swap(x, y);
    if(x.first > 0) return make_pair(u, x.second + y.second + Dis(x.first, y.first) - 1);
    else if(y.first > 0) { Move(y.first, y.second, u, D - x.second); return y; }
    else return max(x, y); 
}
// pair<int, int> Add(int u, pair<int, int> x, pair<int, int> y) {
//     pair<int, int> z = _Add(u, x, y);
//     cerr << u << " (" << x.first << ", " << x.second << ") (" << y.first << ", " << y.second << ") " <<
//     " (" << z.first << ", " << z.second << ")\n";
//     return z;
// }
inline void Process(int u, pair<int, int> &h) {
    if(h.first < 0) {
        if(h.second == D - 1) h = make_pair(u, 1);
        else h.second++;
    }
}
void Dfs3(int u, int _fa) {
    f[u] = make_pair(-1, 0);
    for(auto v : e[u]) if(v != _fa) {
        Dfs3(v, u);
        pair<int, int> h = f[v];
        Process(u, h), f[u] = Add(u, f[u], h);
    }
}
void Dfs4(int u, int _fa) {
    // cerr << "D4 " << u << ' ' << g[u].first << ' ' << g[u].second << endl; 
    pair<int, int> t = make_pair(-1, 0); vector<int> vec = e[u];
    if(_fa) ans = min(ans, (f[u].first < 0 ? 1 : f[u].second) + (g[u].first < 0 ? 1 : g[u].second));
    for(auto v : vec) if(v != _fa) g[v] = make_pair(-1, 0);
    for(auto v : vec) if(v != _fa) {
        g[v] = Add(u, g[v], t);
        pair<int, int> h = f[v];
        Process(u, h), t = Add(u, t, h);
    }
    reverse(vec.begin(), vec.end());
    if(_fa) t = g[u], Process(u, t);
    else t = make_pair(-1, 0);
    for(auto v : vec) if(v != _fa) {
        g[v] = Add(u, g[v], t), Dfs4(v, u);
        pair<int, int> h = f[v];
        Process(u, h), t = Add(u, t, h);
    }
}
bool Check(int d) {
    D = d, Dfs3(1, 0), ans = f[1].first < 0 ? 1 : f[1].second, Dfs4(1, 0);
    // cerr << "Check " << d << endl;
    // for(int i = 1; i <= n; i++) cerr << f[i].first << ' ' << f[i].second << " | ";
    // cerr << endl;
    // for(int i = 2; i <= n; i++) cerr << g[i].first << ' ' << g[i].second << " | ";
    // cerr << endl;
    return ans <= k;
}
void Solve() {
    int i, j; n = Read(), k = Read(), cntdfn = 0;
    for(i = 1; i <= n; i++) e[i].clear();
    for(i = 1; i < n; i++) {
        int u = Read(), v = Read();
        e[u].emplace_back(v), e[v].emplace_back(u);
    }
    if(k == n) { printf("0\n"); return ; }
    Dfs(1, 0);
    // g[1] = -1, Dfs2(1, 0);
    for(i = 1; i < 20; i++) for(j = 1; j <= n; j++) anc[i][j] = anc[i - 1][anc[i - 1][j]];
    int l = 1, r = n - 1, mid, res = r;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(Check(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    Write(res), putchar('\n');
}
int main() {
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
    int c = Read(), T = Read(), i;
    for(i = 1; i < N; i++) lowbit[i] = __lg(i & -i);
    while(T--) Solve();
}