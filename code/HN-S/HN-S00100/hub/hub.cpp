#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 15;

int c, t, n, k, vis[N], d[N][N];
vector <int> v[N];

void dfs (int x, int y) {
  vis[x] = 1;
  for (int i : v[x]) {
    if (vis[i] || !((y >> i - 1) & 1)) continue;
    dfs(i, y);
  }
}

void dfs1 (int x, int fa, int rt, int dd) {
  d[rt][x] = dd;
  for (int i : v[x]) {
    if (i == fa) continue;
    dfs1(i, x, rt, dd + 1);
  }
}

int main () {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> c >> t; t--;) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      v[i].clear();
      vis[i] = 0;
      for (int j = 1; j <= n; j++) {
        d[i][j] = 0;
      }
    }
    for (int i = 1, x, y; i < n; i++) {
      cin >> x >> y;
      v[x].emplace_back(y);
      v[y].emplace_back(x);
    }
    for (int i = 1; i <= n; i++) {
      dfs1(i, i, i, 0);
    }
    int ans = n;
    for (int i = 0; i < (1 << n); i++) {
      if (__builtin_popcount(i) != k) continue;
      for (int j = 1; j <= n; j++) {
        vis[j] = 0;
      }
      for (int j = 1, t = 0; j <= n && t < 2; j++) {
        if (((i >> j - 1) & 1) && !vis[j]) {
          dfs(j, i);
          t++;
        }
      }
      int zs = 0;
      for (int j = 1; j <= n; j++) {
        if (((i >> j - 1) & 1) && !vis[j]) {
          zs = n + 1;
          break;
        }
        int mn = n;
        for (int k = 1; k <= n; k++) {
          if ((i >> k - 1) & 1) {
            mn = min(mn, d[j][k]);
          }
        }
        zs = max(zs, mn);
      }
      ans = min(ans, zs);
    }
    cout << ans << '\n';
  }
  return 0;
}