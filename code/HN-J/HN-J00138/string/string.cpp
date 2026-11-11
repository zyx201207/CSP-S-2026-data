#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, cnt[N];
ll ans, l[N], r[N];
char c[N];

int main() {
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> cnt[i] >> c[i];
    l[i] = r[i - 1] + 1, r[i] = l[i] + cnt[i] - 1;
  }
  for (int i = 1, j = n; i < j; ) {
    if (r[i] - l[i] + 1 == r[j] - l[j] + 1) {
      ans += c[i] == c[j] ? 0 : r[i] - l[i] + 1;
      i++, j--;
    } else if (r[i] - l[i] + 1 < r[j] - l[j] + 1) {
      ans += c[i] == c[j] ? 0 : r[i] - l[i] + 1;
      r[j] -= r[i] - l[i] + 1;
      i++;
    } else {
      ans += c[i] == c[j] ? 0 : r[j] - l[j] + 1;
      l[i] += r[j] - l[j] + 1;
      j--;
    }
  }
  cout << ans;
  return 0;
}
