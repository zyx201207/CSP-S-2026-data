#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n;
ll m, a[N], sum[N];
bool check(int len) {
  for (int l = 1, r = len; r <= n; l ++, r ++)
    if (len * a[r] - (sum[r] - sum[l - 1]) <= m) return true;
  return false;
}
int bs(int l, int r) {
  while (l < r) {
    int mid = l + r + 1 >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }
  return l;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i ++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
  cout << bs(1, n);
  return 0;
}