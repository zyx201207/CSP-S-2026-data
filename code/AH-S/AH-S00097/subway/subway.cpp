#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge {
    int l, r, v;
} ed[500510];
int c, n, m, d, q, tot;
int w[500510], fa[500510], f[20][500510], ds[500510];
vector<pair<int, int>> e[500510];
bool b[500510];
ll dist[500510];

int find(int x) {
    if(fa[x] == x) 
        return x;
    return fa[x] = find(fa[x]);
}
inline void merge(int x, int y) {
    fa[find(x)] = find(y);    
}

bool cmp(const edge &x, const edge &y) {
    return x.v < y.v;
}

inline void solve() {
    sort(ed + 1, ed + 1 + tot, cmp);
    for(int i = 1; i <= tot; i++) {
        int l = ed[i].l, r = ed[i].r;
        if(find(l) != find(r)) {
            merge(l, r);
            e[l].push_back({r, ed[i].v});
            e[r].push_back({l, ed[i].v});
        }
    }
}

inline void dfs(int p) {
    b[p] = 1;
    for(auto i : e[p]) {
        int x = i.first, v = i.second;
        if(!b[x]) {
            f[0][x] = p;
            dist[x] = dist[p] + v;
            ds[x] = ds[p] + 1;
            dfs(x);
        }
    }
}

int lca(int x, int y) {
    if(ds[x] > ds[y]) {
        int l = ds[x] - ds[y];
        for(int i = 0; i < 20; i++) {
            if((l >> i) & 1) {
                x = f[i][x];
            }
        }
    }else if(ds[x] < ds[y]) {
        int l = ds[y] - ds[x];
        for(int i = 0; i < 20; i++) {
            if((l >> i) & 1) {
                y = f[i][y];
            }
        }
    }
    if(x == y) 
        return x;
    for(int i = 19; i >= 0; i--) {
        if(f[i][x] != f[i][y]) {
            x = f[i][x], y = f[i][y];
        }
    }
    return f[0][x];
}

int main() { 
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
    }
    for(int i = 1; i <= m + n; i++) {
        fa[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for(int j = 1; j <= k; j++) {
            int a, t;
            scanf("%d%d", &a, &t);
            ed[++tot] = {a, m + i, t};
        }
    }
    solve();
    dist[1] = 0;
    memset(b, 0, sizeof(b));
    dfs(1);
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i <= tot; i++) {
            f[j][i] = f[j - 1][f[j - 1][i]];
        }
    }
    while(q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int z = lca(x, y);
        printf("%lld\n", dist[y] - dist[z] + dist[x] - dist[z] + w[x] + w[y]);
    }
    return 0;
}