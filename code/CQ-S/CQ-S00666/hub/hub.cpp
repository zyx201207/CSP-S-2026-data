#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
vector<int> h[N];
int n, k;
int Fa[N];
int siz[N], dep[N];
int du[N], d[N];
int S[N], q[N];
int mi[N];
bool st[N];
void dfs1(int u, int fa) {
    Fa[u] = fa;
    dep[u] = dep[fa] + 1;
    siz[u] = (d[u] == 0);
    int num = 0;
    for (int x : h[u]) if (x != fa) {
        dfs1(x, u);
        if (siz[x]) num ++;
        siz[u] += siz[x];
    }
    if (d[u] == 0 || num > 1) st[u] = 1;
}
bool check(int mid) {
    for (int i = 1; i <= n; i ++ ) du[i] = h[i].size(), d[i] = mid, st[i] = 0;
    int hh = 1, tt = 0;
    for (int i = 1; i <= n; i ++ ) if (du[i] == 1) q[++tt] = i;
    int num = 0;
    while (hh <= tt) {
        int u = q[hh ++ ];
        if (!d[u]) continue;
        num ++;
        for (int x : h[u]) {
            du[x] --;
            d[x] = min(d[x], d[u] - 1);
            if (du[x] == 1) q[++tt] = x;
        }
    }
    if (n - num <= k) return true;
    int rt = 0;
    for (int i = 1; i <= n; i ++ ) if (!d[i]) rt = i;
    dfs1(rt, 0);
    for (int i = 1; i <= n; i ++ ) if (st[i] && i != rt) {
        int u = i;u = Fa[u];
        int Cnt = 0;
        while (!st[u]) S[++Cnt] = u, u = Fa[u];
        if (k >= n - num - Cnt) {
            int Mi = Cnt + 1;
            for (int i = 1; i <= Cnt; i ++ ) mi[i] = 1e9;
            for (int i = 1; i <= Cnt; i ++ ) if (i - d[S[i]] >= 1) mi[i - d[S[i]]] = min(mi[i - d[S[i]]], i + d[S[i]]);
            for (int i = Cnt; i; i -- ) {
                Mi = min(Mi, mi[i]);
                if (k >= n - num - Cnt + (i - 1) + Cnt - Mi + 1) return true;
            }
        }
    }
    return false;
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cas, T;cin >> cas >> T;
    while (T -- ) {
        cin >> n >> k;
        for (int i = 1; i <= n; i ++ ) h[i].clear();
        for (int i = 1; i < n; i ++ ) {
            int x, y;cin >> x >> y;
            h[x].push_back(y);
            h[y].push_back(x);
        }
        if (n == k) {
            cout << 0 << '\n';
            continue;
        }
        int l = 1, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
    // cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}