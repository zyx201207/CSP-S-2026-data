#include <bits/stdc++.h>
using namespace std;
int main()
{
   freopen(card.in,"r",stdin);
   freopen(card.out,"w",stdout);
   int n,m,a[100000005];
   for (int i = 1;i<= n;i++)
   {
       cin >> a[i];
   }
   int maxx=-100;
   for (int i = 1;i<= n;i++)
   {
       for (int j = i+1;j<= n;j++)
       {
           if(a[i]&a[j]>maxx)
           {
               maxx=a[i]&a[j];
           }
       }
   }
   cout << maxx;
   return 0;
}
