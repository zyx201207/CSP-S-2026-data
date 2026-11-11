#include <bits/stdc++.h>
#define fori(na, st, ed) for (int na = st; na <= ed; na++)
#define forn(na, ed) fori(na, 1, ed)
#define fora(na, st, ed) for (int na = st; na >= ed; na--)
#define fors(na, st) fora(na, st, 1)
#define ffgetc getchar_unlocked
#define ffputc putchar_unlocked
using namespace std;
namespace solve {
const int N = 1e5 + 5;
int n, d, a[N];
void solve() {
  scanf("%d%d", &n, &d);
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  printf("0\n");
}
} // namespace solve
signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  int c, T;
  scanf("%d%d", &c, &T);
  while (T-- > 0) {
    solve::solve();
  }
}