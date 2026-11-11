#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;
bool ans1, ans2, ans3, ans4;

int main() {
#ifndef LOCAL
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
#endif
  cin >> c1 >> s1 >> c2 >> s2;

  ans1 = c1 == c2;
  ans2 = ans1 && s1[0] == s2[0] && s1[1] == s2[1];

  if (s2[2] >= 'A' && s2[2] <= 'C') {
    if (s1[2] >= 'A' && s1[2] <= 'C') {
      ans3 = ans2;
      if (ans2 && abs(s1[2] - s2[2] <= 1)) ans4 = true;
    }
  } else if (s1[2] == 'F' || s1[2] == 'D') {
    ans3 = ans2;
    if (ans2 && abs(s1[2] - s2[2] <= 1)) ans4 = true;
  }

  printf("%d%d%d%d", (int)ans1, (int)ans2, (int)ans3, (int)ans4);
  return 0;
}
