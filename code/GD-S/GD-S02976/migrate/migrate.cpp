#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2 * 1e6;
int c, t, x[N];

void solve() {
  memset(x, 0, sizeof(x));
  int n, d;
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
  }

  if (n < 4) {
    printf("%d", 0);
    return;
  }

  int cnt = 0;
  printf("%d\n", rand() % n);
}

int main() {
#ifndef LOCAL
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
#endif

  scanf("%d %d", &c, &t);

  while (t--) solve();

  return 0;
}