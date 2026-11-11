#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, m, a[MAXN], ans;

void dfs(int x, int cnt, int res) {
  if (cnt > m) return;
  if (x == n + 1) {
    if (cnt == m) ans = max(ans, res);
    return;
  }
  dfs(x + 1, cnt + 1, res & a[x]);
  dfs(x + 1, cnt, res);
}

int main() {
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; cin >> a[i++]);
  if (n <= 20) {
    dfs(1, 0, (1 << 30) - 1);
    cout << ans;
    return 0;
  }
  if (m == 1) {
    cout << *max_element(a + 1, a + n + 1);
    return 0;
  }
  for (int i = 0; i < 30; i++) {
    sort(a + 1, a + n + 1, [&](const int x, const int y) {
      if ((x >> i & 1) != (y >> i & 1)) return (x >> i & 1) > (y >> i & 1);
      return x > y;
    });
    int res = (1 << 30) - 1;
    for (int i = 1; i <= m; i++) res &= a[i];
    ans = max(ans, res);
  }
  cout << ans;
  return 0;
}
