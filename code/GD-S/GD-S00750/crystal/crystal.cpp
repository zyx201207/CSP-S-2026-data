#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 500010;
int n, m, a[N], s[N], ans;
signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  scanf("%lld%lld", &n, &m);
  for(int i = 1; i <= n; i++)
    scanf("%lld", &a[i]);
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
    int l = 1, r = i, best = i;
    while(l <= r) {
      int mid = (l + r) / 2;
      if((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) <= m) {
        best = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    ans = max(ans, i - best + 1);
  }
  printf("%lld\n", ans);
  return 0;
}

