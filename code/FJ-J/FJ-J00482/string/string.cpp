#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
int a[N];
char c[N];

int main() {
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i] >> c[i];
  
  i64 p = 0, q = 0, u = 0, ans = 0;
  for (int i = 1, j = n; i <= n; i++) {
    p += a[i];
    while (q < p && q + a[j] - u <= p) {
      if (c[i] != c[j]) ans += a[j] - u;
      q += a[j--] - u;
      u = 0;
    }
    
    if (q < p) {
      u += p - q;
      if (c[i] != c[j]) ans += p - q;
      q = p;
    }
  }
  
  std::cout << ans / 2 << '\n';
}
