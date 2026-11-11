#include <bits/stdc++.h>
#define fori(na, st, ed) for (int na = st; na <= ed; na++)
#define forn(na, ed) fori(na, 1, ed)
#define fora(na, st, ed) for (int na = st; na >= ed; na--)
#define fors(na, st) fora(na, st, 1)
#define ffgetc getchar_unlocked
#define ffputc putchar_unlocked
using namespace std;
namespace solve {
const int N = 1e6 + 5;
int n, k, maxf, f, cntw, c[N];
vector<int> e[N];
void dfs(int x, int cnt, int fa) {
  if (cnt > maxf) {
    maxf = cnt;
    f = x;
  }
  for (auto y : e[x]) {
    if (y != fa) {
      dfs(y, cnt + 1, x);
    }
  }
}
void dfs3(int x, int cnt, int fa) {
  if (c[x] < c[fa]) {
    return;
  }
  c[x]--;
  for (auto y : e[x]) {
    if (y != fa) {
      dfs(y, cnt + 1, x);
    }
  }
}
void dfs4(int x, int cnt, int fa) {
  if (c[x] < c[fa]) {
    return;
  }
  c[x] = cnt;
  if (cnt > k) {
    return;
  }
  for (auto y : e[x]) {
    if (y != fa) {
      dfs(y, cnt + 1, x);
    }
  }
}
void dfs2(int x, int fa) {
  c[x] = c[fa] + 1;
  if (c[x] > k) {
    if (cntw > 1) {
      dfs3(x, 0, 0);
    } else {
      dfs4(x, 0, 0);
    }
    cntw++;
  }
  for (auto y : e[x]) {
    if (y != fa) {
      dfs2(y, x);
    }
  }
}
bool chk(int x) {
  cntw = 0;
  dfs2(f, 0);
  return cntw <= x;
}
void solve() {
  scanf("%d%d", &n, &k);
  forn(i, n) { e[i].clear(); }
  forn(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0, 0);
  dfs(f, 0, 0);
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (chk(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", l);
}
} // namespace solve
signed main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  int c, T;
  scanf("%d%d", &c, &T);
  while (T-- > 0) {
    solve::solve();
  }
}