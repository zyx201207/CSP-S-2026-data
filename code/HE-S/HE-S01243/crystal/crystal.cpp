#include <bits/stdc++.h>
#define up(i,l,r) for (int i = l, E##i = r; i <= E##i; ++i)
using namespace std;
using L = long long;
constexpr L N = 5e5 + 5;
L n, m, a[N], s[N], ans;
int main () {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  up (i, 1, n) cin >> a[i];
  sort(a + 1, a + 1 + n);
  up (i, 1, n) s[i] = s[i - 1] + a[i];
  L l = 0;
  up (i, 1, n) {
    while (a[i] * (i - l) - (s[i] - s[l]) > m) ++l;
    ans = max(ans, i - l);
  }
  cout << ans;
  return 0;
}
