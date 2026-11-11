#include <bits/stdc++.h>
using namespace std;
int main()
{
  //freopen("travel.in","r",stdin);
  //freopen("travel.out","w",stdout);
  string c1,s1,c2,s2;
  cin >> c1 >> s1 >> c2 >> s2;
  //char list[18][5];
  //for (int i = 0;i < 5;i++)
  //	for (int j = 0;j < 18;j++) list[j][i] = 'A' + i;
  bool A = (c1 == c2);
  bool B = (A && (s1[0] == s2[0]) && (s1[1] == s2[1]));
  bool C = (B && );
  bool D = (abs(s1[2] - s2[2]) == 1);
  cout << A << B << C << D;
  return 0;
}
