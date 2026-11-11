#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IL inline
const int N = 5e5 + 5;
int n;
ll m, a[N], s[N];
bool chk(int l, int r, int k) {
  ll cost = (r - l + 1) * a[k] - (s[r] - s[l - 1]);
  return cost <= m;
}
int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i)
    s[i] = s[i - 1] + a[i];
  int ans = 0, mn = 1;
  for (int i = 1; i <= n; ++i) {
    while (!chk(mn, i, i)) ++mn;
    ans = max(ans, i - mn + 1);
  }
  cout << ans << '\n';
  return 0;
}