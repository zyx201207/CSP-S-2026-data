#include <bits/stdc++.h>
using namespace std;
int main()
{
   freopen(travel.in,"r",stdin);
   freopen(travel.out,"w",stdout);
   int c1,c2;
   char s1[10],s2[10];
   cin >> c1;
   for (int i = 1;i <= 3;i++)
   {
       cin >> s1[i];
   }
   cin >> c2;
   for (int i = 1;i <= 3;i++)
   {
       cin >> s2[i];
   }
   if(c1==c2)
   {
       cout << 1;
   }
   if(s1[1]==s2[1]&&s1[2]==s2[2])
   {
       cout << 1;
       if('A'<=s1[3]<='C'&&'A'<=s2[3]<='C')
       {
           cout << 1;
           if(s1[3]-s2[3]==1||s2[3]-s1[3]==1)
           {
               cout << 1;
           }
       }
       if('D'<=s1[3]<='F'&&'D'<=s2[3]<='F')
       {
           cout << 1;
           if(s1[3]-s2[3]==3||s2[3]-s1[3]==3)
           {
               cout << 1;
           }
       }
   }
   return 0;
}
