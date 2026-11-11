#include <iostream>
#include <string>
#include <vector>

long long cnt;
long long a[200005];
char c[200005];

int main() {
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  
  long long n;
  std::cin >> n;
  for (long long i = 1; i <= n; i++) std::cin >> a[i] >> c[i];

  long long leidx = 1, rigidx = n;
  while (leidx < rigidx) {
    if (a[rigidx] > a[leidx]) {
      a[rigidx] -= a[leidx];
      cnt += a[leidx] * (c[leidx] != c[rigidx] ? 1 : 0);
      a[leidx] = 0;
      if (a[rigidx] == 0) rigidx--;
      leidx++;
    }
    else {
      a[leidx] -= a[rigidx];
      cnt += a[rigidx] * (c[leidx] != c[rigidx] ? 1 : 0);
      a[rigidx] = 0;
      if (a[leidx] == 0) leidx++;
      rigidx--;
    }
  }
  std::cout << cnt << '\n';
  return 0;
}