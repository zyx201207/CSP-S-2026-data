#include <algorithm>
#include <iostream>

int n, m;
int a[200005];

int main() {
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::sort(a + 1, a + n + 1, std::greater<int>());
  int sum = a[1];
  for (int i = 1; i <= m; i++) sum &= a[i];
  std::cout << sum << '\n';
  return 0;
}
