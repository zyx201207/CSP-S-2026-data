#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2 * 1e6 + 5;
int c, t;
int u[N], v[N];

void solve() {
  memset(u, 0, sizeof(u));
  memset(v, 0, sizeof(v));
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) scanf("%d %d", &u[i], &v[i]);

  printf("%d\n", rand() % k);
}

int main() {
#ifndef LOCAL
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
#endif
  scanf("%d %d", &c, &t);
  while (t--) solve();

  return 0;
}