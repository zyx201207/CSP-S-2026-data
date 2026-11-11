#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 5e5 + 10;

i64 a[N];
i64 s[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);

  int n;
  i64 m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }

  int res = 1;
  for (int i = 2; i <= n; i++) {
    int l = 1, r = i;

    while (l < r) {
      int mid = (l + r) / 2;
      i64 sum = 1ll * (i - mid) * a[i] - (s[i - 1] - s[mid - 1]);

      if (sum <= m) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    res = max(res, i - l + 1);
  }

  cout << res << '\n';

  return 0;
}
