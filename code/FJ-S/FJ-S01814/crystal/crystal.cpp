#include <bits/stdc++.h>

using LL = long long;
using namespace std;

const int N = 5e5 + 10;
LL a[N], s[N];

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n;
  LL m;
  cin >> n >> m;
  
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = 1, r = i, o = 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int p = i - mid + 1;
      LL c = s[i] - s[p - 1];
      if (a[i] * mid - c <= m) {
        o = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    ans = max(ans, o);
  }
  cout << ans << '\n';
  return 0;
}