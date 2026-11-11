#include <bits/stdc++.h>
#define eb emplace_back

using namespace std;

const int N = 1010;
vector<int> g[N];
int dep[N], fa[N], id[N], n, m;
int st[N], f[N][2][3], nf[2][3];
int dis[N][N], rt = 5;

void dfs(int u, int p) {
  dep[u] = dep[fa[u] = p] + 1;
  for (auto v : g[u]) {
    if (v != p) dfs(v, u);
  }
}

void dfs3(int u, int p, int d[]) {
  for (auto v : g[u]) {
    if (v != p) {
      d[v] = d[u] + 1;
      dfs3(v, u, d);
    }
  }
}

void dfs2(int u, int p) {
  memset(f[u], 0x3f, sizeof f[u]);
  if (st[u]) {
    f[u][1][1] = 1;
  }
  if (!st[u]) {
    f[u][0][0] = 0;
    f[u][1][1] = 1;
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs2(v, u);
    memset(nf, 0x3f, sizeof nf);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; i + j < 3; j++) {
        nf[0][i + j] = min(nf[0][i + j], f[u][0][i] + min(f[v][0][j], f[v][1][j]));
        nf[1][i + j] = min(nf[1][i + j], f[u][1][i] + f[v][0][j]);
        if (i + j - 1 >= 0) {
          nf[1][i + j - 1] = min(nf[1][i + j - 1], f[u][1][i] + f[v][1][j]);
        }
      }
    }
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        f[u][i][j] = nf[i][j];
      }
    }
  }
}

bool check(int k) {
  fill(st + 1, st + n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int u = id[i];
    int p = u;
    for (int i = 1; i <= k; i++) {
      if (p == 1) break;
      p = fa[p];
    }
    int flg = 0;
    for (int j = 1; j <= n; j++) {
      if (dis[u][j] <= k && st[j]) {
        flg = 1;
        break;
      }
    }
    if (!flg) st[p] = 1;
  }
  dfs2(rt, 0);
  int ans = n + 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ans = min(ans, f[rt][i][j]);
    }
  }
  return ans <= m;
}
int ct = 0;

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    fa[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].eb(v);
    g[v].eb(u);
  }
  dfs(rt, 0);
  for (int i = 1; i <= n; i++) {
    dis[i][i] = 0;
    dfs3(i, 0, dis[i]);
  }
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, [&](int i, int j) { return dep[i] > dep[j]; });
  int l = 1, r = n, ans = n;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (check(m)) {
      r = m - 1;
      ans = m;
    }
    else {
      l = m + 1;
    } 
  }
  cout << ans << '\n';
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int c, T;
  cin >> c >> T;
  while (T--) {
    ct++;
    solve();
  }
  return 0;
}