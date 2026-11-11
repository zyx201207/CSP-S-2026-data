#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n;
pair<ll, char> a[MAXN];

int main() {
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    auto &[x, c] = a[i];
    cin >> x >> c;
  }
  ll len1 = 0, len2 = 0, ans = 0;
  for (int i = 1, j = n; i <= j; ) {
    for (; i <= j && len1 <= len2; i++) {
      ans += min(len2 - len1, a[i].first) * (a[i].second != a[j + 1].second), len1 += a[i].first;
    }
    for (; j >= i && len2 <= len1; j--) {
      ans += min(len1 - len2, a[j].first) * (a[j].second != a[i - 1].second), len2 += a[j].first;
    }
  }
  cout << ans;
  return 0;
}
