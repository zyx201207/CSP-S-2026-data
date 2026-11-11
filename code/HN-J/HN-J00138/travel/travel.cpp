#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string a, b, c, d;

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b >> c >> d;
  if (a != c) {
    cout << "0000";
    return 0;
  }
  if (b[0] != d[0] || b[1] != d[1]) {
    cout << "1000";
    return 0;
  }
  int x = b[2] - 'A' + 1, y = d[2] - 'A' + 1;
  if (x > y) swap(x, y);
  if (!((x <= 3 && y <= 3) || (x > 3 && y > 3))) {
    cout << "1100";
    return 0;
  }
  if ((x == 1 && y == 2) || (x == 2 && y == 3) || (x == 4 && y == 6)) {
    cout << "1111";
  } else {
    cout << "1110";
  }
  return 0;
}
