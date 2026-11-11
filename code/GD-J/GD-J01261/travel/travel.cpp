#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
  int c1, c2;
  string s1, s2;
  cin >> c1 >> s1 >> c2 >> s2;
  int x = (s1[0] - '0') * 10 + s1[1] - '0';
  int y = (s2[0] - '0') * 10 + s2[1] - '0';
  char seat1 = s1[2], seat2 = s2[2]; 
  if (seat1 > seat2) swap(seat1, seat2);
  vector<int> ans(4); 
//  cout << x << ' ' << y << ' ' << seat1 << ' ' << seat2 << '\n';
  // same side: ABC, DF
  vector<int> side(27, 999);
  side['A' - 'A'] = side['B' - 'A'] = side['C' - 'A'] = 1;
  side['D' - 'A'] = side['F' - 'A'] = 2;
  if (c1 == c2) {
    ans[0] = 1;
    if (x == y) {
      ans[1] = 1;
//      cout << side[seat1 - 'A'] << ' ' << side[seat2 - 'A'] << '\n';
      if (side[seat1 - 'A'] == side[seat2 - 'A']) {
        ans[2] = 1;
        if (seat1 == 'A' && seat2 == 'B') ans[3] = 1;
        if (seat1 == 'B' && seat2 == 'C') ans[3] = 1;
        if (seat1 == 'D' && seat2 == 'F') ans[3] = 1;
      }
    }
  }
  for (auto& x : ans) cout << x;
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  freopen("travel.out", "w", stdout);
  freopen("travel.in", "r", stdin);
  
  int t = 1;
  while (t--) solve();
  return 0;
}

