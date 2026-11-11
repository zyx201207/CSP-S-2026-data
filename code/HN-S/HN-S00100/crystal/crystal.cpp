#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 5e5 + 5;

LL n, m, a[N], zs[N], ans;

int main () {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    zs[i] = zs[i - 1] + a[i];
  }
  for (LL i = 1, j = 1; i <= n; i++) {
    for (; (i - j + 1) * a[i] - zs[i] + zs[j - 1] > m; j++) {
    }
    ans = max(ans, i - j + 1);
  }
  cout << ans;
  return 0;
}