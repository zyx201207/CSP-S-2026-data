#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int n, ans;
ll m, a[N], pre[N];

bool check(int x, int i, int k) {
  return k * (i - x + 1) - pre[i] + pre[x - 1] <= m;
}

int puck(int l, int r, int i, ll x) {
  while (l < r) {
    int mid = l + r >> 1;
    check(mid, i, x) ? r = mid : l = mid + 1;
  }
  return l;
}

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    int x = puck(1, i, i, a[i]);
    ans = max(ans, i - x + 1);
  }
  cout << ans;
  return 0;
}
