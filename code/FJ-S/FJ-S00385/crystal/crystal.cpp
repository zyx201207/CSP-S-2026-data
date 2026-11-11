#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

using ll = long long;

ll n, m, ans;
ll a[500005], s[500005];

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];
    
  for (int i = 1; i <= n; i++) {
    ll l = 1, r = i, mid;
    while (l < r) {
      mid = l + r >> 1;
      ll w = s[mid - 1] - s[i] + a[i] * (i - mid + 1);
      if (w <= m)
        r = mid;
      else
        l = mid + 1;
    }
    ans = max(ans, i - l + 1);
  }
  cout << ans << endl;
  return 0;
}


