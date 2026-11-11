#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2 * 1e5 + 5;
int n, m;
ll a[N];

int main() {
#ifndef LOCAL
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
#endif
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

  sort(a + 1, a + 1 + n, greater<ll>());

  printf("%lld", a[m]);
  return 0;
}