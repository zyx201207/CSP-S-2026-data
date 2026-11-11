#include <bits/stdc++.h>

namespace ZeroOf149 {

using std::cin;
using std::cout;

using ll = long long;

constexpr int N = 5e5 + 5;

int n, Ans = 1;
ll m, a[N], pre[N];

int my_main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j < i && (i - j + 1ll) * a[i] - pre[i] + pre[j - 1] > m) ++j;
    Ans = std::max(Ans, i - j + 1);
  }
  cout << Ans;
  
  return 0;
}

}

int main() { return ZeroOf149::my_main(); }

