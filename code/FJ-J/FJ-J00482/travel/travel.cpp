#include <bits/stdc++.h>

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  
  std::string c1, s1, c2, s2;
  std::cin >> c1 >> s1 >> c2 >> s2;
  
  if (s1[2] == 'F') s1[2]--;
  if (s2[2] == 'F') s2[2]--;
  
  bool A = c1 == c2;
  bool B = A && s1[0] == s2[0] && s1[1] == s2[1];
  bool C = B && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'));
  bool D = C && (s1[2] + 1 == s2[2] || s2[2] + 1 == s1[2]);
  std::cout << A << B << C << D << '\n';
}
