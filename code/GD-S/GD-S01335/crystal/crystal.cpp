#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<i64> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int ans = 0;
  i64 pre = 0;
  i64 mn = 1e18;
  int mnid = -1;
  int ele = 0;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    i64 cost = a[i] * ele - pre;
//    cout << "We are now " << i << " and cost " << cost << ' ' << pre << ' ' << ele << ' ' << a[i] << '\n';
    if (cost > m) {
      while (!s.empty() && a[i] * ele - pre > m) pre -= *s.begin(), s.erase(*s.begin()), ele--;
//      cout << "Deleted some large now cost " << a[i] * ele - pre << '\n';
      cost = a[i] * ele - pre;
      if (cost > m) {
//        cout << "Too large" << cost << '\n';
        continue;
      }
    }
//    cout << cost << '\n';
    ele++;
    ans = max(ans, ele);
    pre += a[i];
    s.insert(a[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  
  int t = 1;
  while (t--) solve();
  return 0;
}

