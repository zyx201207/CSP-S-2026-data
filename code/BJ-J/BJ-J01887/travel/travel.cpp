#include <iostream>
using namespace std;
int I(char c,string s)
{
int l = s.length();
for (int i = 0;i < l;i++)
{
if (s[i] == c){return 1;}
}
return 0;
}
int C1(char x,char y)
{
return (I(x,"abc") && I(y,"df")) || (I(x,"df") && I(y,"abc"));
}
int C2(char x,char y)
{
if (x == 'A' && y == 'B'){return 1;}
if (x == 'B' && y == 'C'){return 1;}
if (x == 'D' && y == 'F'){return 1;}
if (x == 'B' && y == 'A'){return 1;}
if (x == 'C' && y == 'B'){return 1;}
if (x == 'F' && y == 'D'){return 1;}
return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
string c1,s1,c2,s2;cin >> c1 >> s1 >> c2 >> s2;
cout << (c1 == c2);
cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]);
cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && C1(s1[2],s2[2]));
cout << (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && C2(s1[2],s2[2]));
return 0;
}
