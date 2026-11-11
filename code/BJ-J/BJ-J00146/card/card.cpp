#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005], nxt[500005], lst[500005], lstcnt[500005], fir[300005], sz[500005];
int ans[300005], tmp[300005];
vector <int> g[500005];

int find (int x) {
    if (nxt[x] == n + 1) {
        return x;
    }
    return nxt[x] = find(nxt[x]);
}

void dfs (int u, int f) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == f) {
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
    }
    ans[a[u]] += sz[u];
}

int main () {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        if (tmp[a[i]] == 0) {
            nxt[i] = n + 1;
        } else {
            nxt[i] = tmp[a[i]];
        }
        tmp[a[i]] = i;
    }
    for (int i = 1; i <= m; ++i) {
        tmp[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        lst[i] = tmp[a[i]];
        lstcnt[i] = lstcnt[lst[i]] + 1;
        tmp[a[i]] = i;
    }
    for (int i = n; i >= 1; --i) {
        if (nxt[i] == n + 1) {
            fir[a[i]] = i;
            g[i + 1].push_back(i);
            g[i].push_back(i + 1);
        } else {
            g[find(i) + 1].push_back(i);
            g[i].push_back(find(i) + 1);
        }
    }
    dfs(n + 1, 0);
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
