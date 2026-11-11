// 17.07
#include<iostream>
#include<vector>
#include<utility>
// #include<cassert>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e6 + 10;

struct Edge {
    int v, next;
} pool[2 * N]; int ne, head[N];
inline void addEdge(int u, int v) {
    pool[++ne] = {v, head[u]}, head[u] = ne;
}

int T, n, m;
int dep[N], fa[N], mxd[N];
bool od[N];
vector<int> b[N];

int dx, dy, dd, du, rt;
pii dfs1(int u, int a0) {
    dep[u] = dep[a0] + 1, fa[u] = a0;
    int p = u, pv = 0;
    for(int e = head[u]; e; e = pool[e].next) {
        int v = pool[e].v; if(v == a0) continue;
        pii tmp = dfs1(v, u);
        if(pv + tmp.second + 1 >= dd) dx = p, dy = tmp.first, dd = pv + tmp.second + 1, du = u;
        if(tmp.second + 1 >= pv) p = tmp.first, pv = tmp.second + 1;
    }
    return pii(p, pv);
}

void dfs2(int u, int a0) {
    fa[u] = a0, dep[u] = dep[a0] + 1, mxd[u] = 0;
    if(!a0) dep[u] = 0;
    for(int e = head[u]; e; e = pool[e].next) {
        int v = pool[e].v; if(v == a0) continue;
        dfs2(v, u), mxd[u] = max(mxd[u], mxd[v] + 1);
    }
    b[mxd[u]].push_back(u);
}

// 17.34
bool flag[N]; int deg[N], fa1[N], res1, rt1;
int mn[N];

void dfs35(int u, int a0) {
    mxd[u] = 0, fa[u] = a0;
    for(int e = head[u]; e; e = pool[e].next) {
        int v = pool[e].v; if(v == a0) continue;
        dfs35(v, u), mxd[u] = max(mxd[u], mxd[v] + 1);
    }
}

int dfs3(int u, int a0, int lim) {
    fa1[u] = a0;
    int cnt = 0, ret = -1;
    for(int e = head[u]; e; e = pool[e].next) {
        int v = pool[e].v; if(v == a0 || !flag[v]) continue;
        ++cnt;
    }
    for(int e = head[u]; e; e = pool[e].next) {
        int v = pool[e].v; if(v == a0 || !flag[v]) continue;
        int t = dfs3(v, u, lim);
        // cout << "test: " << u << ' ' << v << ' ' << t << ' ' << cnt << endl;
        if(cnt >= 2 || u == rt1) {
            vector<int> s;
            for(int i = t; i != u; i = fa[i]) s.push_back(i);
            for(int i = 0; i <= s.size() + 1; i++) mn[i] = n + 5;
            // cout << "test" << endl;
            // for(int i : s) cout << i << ' '; cout << endl;
            for(int i = 0; i < s.size(); i++) {
                int x = s[i], tmp = 0;
                for(int e = head[x]; e; e = pool[e].next) {
                    int v = pool[e].v;
                    if(!flag[v]) tmp = max(tmp, mxd[v] + 1);
                }
                // assert(tmp <= lim);
                tmp = lim - tmp;
                if(i - tmp < 0 || i + tmp >= s.size()) continue;
                mn[i - tmp] = min(mn[i - tmp], i + tmp);
            }
            int cur = s.size();
            for(int i = (int)s.size() - 1; i >= 0; i--) {
                cur = min(cur, mn[i]);
                res1 = max(res1, cur - i);
            }
        }
        ret = t;
    }
    if(cnt == 1) return ret;
    return a0;
}

bool check(int mid) {
    int res = 0;
    for(int i = mid; i <= n; i++) res += b[i].size();
    if(res <= m) return true;

    for(int i = 1; i <= n; i++) flag[i] = deg[i] = 0;
    for(int i = mid; i <= n; i++) for(int j : b[i]) flag[j] = 1;
    rt1 = -1;
    for(int i = 1; i <= n; i++) {
        if(!flag[i]) continue;
        for(int e = head[i]; e; e = pool[e].next) {
            int v = pool[e].v; deg[i] += flag[v];
        }
        if(deg[i] && deg[i] != 2) rt1 = i;
    }
    // cout << rt << ' ' << rt1 << endl;
    res1 = 0;
    dfs35(rt1, 0);
    dfs3(rt1, 0, mid);
    if(res - res1 <= m) return true;
    return false;
    // int lim = 0;
    // for(int e = head[rt]; e; e = pool[e].next) {
    //     int v = pool[e].v; if(od[v]) continue;
    //     lim = max(lim, mxd[v] + 1);
    // }
    // if(lim < mid) {
    //     res = 0;
    //     vector<int> tmp;
    //     for(int e = head[rt]; e; e = pool[e].next) {
    //         int v = pool[e].v;
    //         if(od[v]) tmp.push_back(v);
    //     }
    //     assert(tmp.size() == 2);
    //     res = min(dfs(tmp[0], rt, ))
    //     if(res <= m) return true;
    // }
}

void clear() {
    ne = 0, dd = 0;
    for(int i = 1; i <= n; i++) head[i] = od[i] = 0;
    for(int i = 0; i <= n; i++) b[i].clear();
}

int main() {

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T >> T;
    while(T--) {
        cin >> n >> m; clear();
        for(int i = 1; i <= n - 1; i++) {
            int u, v; cin >> u >> v;
            addEdge(u, v), addEdge(v, u);
        }
        if(m == n) { cout << 0 << '\n'; continue; }
        dfs1(1, 0);
        if(dep[dx] - dep[du] >= dep[dy] - dep[du]) swap(dx, dy);
        // cout << dx << ' ' << dy << ' ' << du << endl;
        rt = dy;
        for(int i = 1; i <= (dep[dx] + dep[dy] - 2 * dep[du]) / 2; i++) rt = fa[rt];
        // cout << rt << endl;
        for(int i = dx; i != du; i = fa[i]) od[i] = 1;
        for(int i = dy; i != fa[du]; i = fa[i]) od[i] = 1;
        // assert(rt);
        dfs2(rt, 0);
        // cout << check(1) << endl;
        int l = 1, r = n;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }

    return 0;
}