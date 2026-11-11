#include <bits/stdc++.h>
using namespace std;
int main()
{
   freopen(string.in,"r",stdin);
   freopen(string.out,"w",stdout);
   int n,a[100000005],suma=0,x;
   string c[100000005];
   for (int i = 1;i<= n;i++)
   {
       cin >> a[i];
       cin >> c[i];
       suma += a[i];
   }
   for (int i = 1;i<= n;i++)
   {
       for (int j = 1;j<= a[i];j++)
       {
            b[i]=c[i];
       }
   }
   for (int i = 1;i<= suma;i++)
   {
       while (b[i]!=b[suma+1-i])
       {
            b[suma+1-i] = b[i];
            x++;
       }
   }
   cout << x;
   return 0;
}
