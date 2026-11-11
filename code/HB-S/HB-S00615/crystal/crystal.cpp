#include <bits/stdc++.h>
#define fori(na, st, ed) for (int na = st; na <= ed; na++)
#define forn(na, ed) fori(na, 1, ed)
#define fora(na, st, ed) for (int na = st; na >= ed; na--)
#define fors(na, st) fora(na, st, 1)
#define ffgetc getchar_unlocked
#define ffputc putchar_unlocked
#define int long long
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
namespace solve {
const int N = 5e5 + 5;
int n, m, a[N], s[N], d[N];
/*
a_x - a_1 = a_x - a_{x-1} + a_{x-1} - a_{x-2} + \cdots + a_2 - a_1
= d_x + d_{x-1} + \cdots + d_2

a_x - a_i = d_x + d_{x-1} + \cdots + d_{i+1}

\sum_{i=1}^{x-1} a_x - a_i
= (x-1)\times d_x + (x-2)\times d_{x-1} + \cdots + 1\times d_2
= \sum_{i=2}^x (i-1)\times d_i
*/
bool chk(int x) {
  int nw = 0;
  fori(i, 2, x) { nw += (i - 1) * d[i]; }
  // eprintf("%lld ", nw);
  if (nw <= m) {
    return true;
  }
  fori(i, x + 1, n) {
    nw = nw - a[i - 1] + a[i - x] + (x - 1) * d[i];
    // eprintf("%lld ", nw);
    if (nw <= m) {
      return true;
    }
  }
  return false;
}
void solve() {
  // read(n, m);
  scanf("%lld%lld", &n, &m);
  forn(i, n) { /*read(a[i]);*/
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1);
  forn(i, n) { d[i] = a[i] - a[i - 1]; }
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (chk(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  printf("%lld", l);
  // eprintf("%d", chk(3));
}
} // namespace solve
signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  // freopen("crystal.err", "w", stderr);
  int T = 1;
  while (T-- > 0) {
    solve::solve();
  }
}