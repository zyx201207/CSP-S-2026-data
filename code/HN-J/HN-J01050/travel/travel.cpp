#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string c1, s1, c2, s2;
bool side[6][6], nr[6][6];

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; side[i][j++] = 1);
  }
  side[3][5] = side[5][3] = 1;
  nr[0][1] = nr[1][2] = nr[3][5] = 1;
  nr[1][0] = nr[2][1] = nr[5][3] = 1;
  cin >> c1 >> s1 >> c2 >> s2;
  bool k1 = c1 == c2;
  bool k2 = s1.substr(0, 2) == s2.substr(0, 2);
  bool k3 = side[s1[2] - 'A'][s2[2] - 'A'];
  bool k4 = nr[s1[2] - 'A'][s2[2] - 'A'];
  cout << k1 << (k1 & k2) << (k1 & k2 & k3) << (k1 & k2 & k4);
  return 0;
}
