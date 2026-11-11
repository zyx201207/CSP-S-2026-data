#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 5;
int n;
ll m, a[N];
int main() {
   freopen("crystal.in", "r", stdin);
   freopen("crystal.out", "w", stdout);
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> n >> m;
   for (int i = 1; i <= n; i++) cin >> a[i];
   sort(a + 1, a + n + 1);
   int ans = 0; ll s = 0;
   for (int i = 1, l = 1; i <= n; i++) {
      s += a[i];
      while (a[i] * (i - l + 1) - s > m) s -= a[l], l++;
      ans = max(ans, i - l + 1);
   }
   cout << ans;
   return 0;
}