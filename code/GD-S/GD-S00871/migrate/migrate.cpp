#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 2e6 + 10;

i64 a[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);

  int c, t;
  cin >> c >> t;
  while (t--) {
    int n;
    i64 d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    if (c == 11 || c == 12) {
      i64 x = d / (a[2] - a[1]);
      if (x <= 1) {
        cout << 0 << '\n';
      } else {
        cout << max(n - 2 * x + 1, 0ll) << '\n';
      }
      continue;
    }

    if (c == 13 || c == 14) {
      i64 res = 0;
      for (int i = 1; i <= n; i++) {
        int x = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
        if (x <= i + 1) {
          continue;
        }
        int y = lower_bound(a + 1, a + n + 1, a[x - 1] + d) - a;
        int z = upper_bound(a + 1, a + n + 1, a[x - 1] + d) - a;
        if (a[y] - a[i] > d) {
          res += z - y;
        }
      }
      cout << res << '\n';
    }
  }

  return 0;
}
