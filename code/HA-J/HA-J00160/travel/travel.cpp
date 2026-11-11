#include <cmath>
#include <iostream>
#include <string>
#include <set>

std::set<char> stle = {'A', 'B', 'C'}, strig = {'D', 'F'};

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  std::string c1, s1, c2, s2;
  std::cin >> c1 >> s1 >> c2 >> s2;

  std::cout << (c1 == c2);
  std::cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]);
  std::cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ((stle.count(s1[2]) && stle.count(s2[2])) || (strig.count(s1[2]) && strig.count(s2[2]))));
  std::cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ((stle.count(s1[2]) && stle.count(s2[2])) || (strig.count(s1[2]) && strig.count(s2[2]))) && ((s1[2] - s2[2]) == 1 || (s1[2] - s2[2]) == 1));
  std::cout << '\n';
  return 0;
}