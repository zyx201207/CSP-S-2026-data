#include <bits/stdc++.h>
using namespace std;
const string INDEX[2] = {"ABC", "DF"};
int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  int c1, c2;
  string s1, s2;
  cin >> c1 >> s1 >> c2 >> s2;
  if (c1 == c2) cout << 1;
  else {
    cout << "0000";
    return 0;
  }
  if (s1[0] + s1[1] == s2[0] + s2[1]) cout << 1;
  else {
    cout << "000";
    return 0;
  }
  if (INDEX[0].find(s1[2]) != -1 && INDEX[0].find(s2[2]) != -1 || INDEX[0].find(s1[2]) != -1 && INDEX[0].find(s2[2]) != -1) cout << 1;
  else {
    cout << "00";
    return 0;
  }
  cout << (abs((s1[0] - '0') * 10 + (s1[1] - '0') - abs((s2[0] - '0') * 10 + (s2[1] - '0')) == 1 || abs(s1[2] - s2[2]) == 1));
  return 0;
}
