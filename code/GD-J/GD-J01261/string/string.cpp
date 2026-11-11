#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
  string s;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    char c;
    cin >> c;
    for (int i = 1; i <= x; i++) s += c;
  }
//  cout << s << '\n';
  long long ans = 0;
  for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
    if (s[i] != s[j]) ans++;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  freopen("string.out", "w", stdout);
  freopen("string.in", "r", stdin);
  
  int t = 1;
  while (t--) solve();
  return 0;   
}

