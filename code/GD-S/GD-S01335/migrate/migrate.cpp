#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  cout << n * (n - 1) / 2 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  
  int c, t;
  cin >> c >> t;
  while (t--) solve();
  return 0;
}


