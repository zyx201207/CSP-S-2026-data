#include <bits/stdc++.h>
using namespace std;
int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   int m,d;
   string n[10],u[10];
   cin >> m;
   for(int i=1;i<=3;i++)
   {
       cin >> n[i];
   }
   cin >> d;
   for(int i=1;i<=3;i++)
   {
       cin >> u[i];
   }
   if(m==d)
   {
       cout<<" 1";
   }
   else
   {
       cout << "0";
   }
   int o=0;
   for(int i=1;i<=2;i++)
   {
       if(n[i]==u[i])
       {
           o++;
       }
   }
   if(o==2)
   {
       cout << "1";
   }
   else
   {
       cout << "0";
   }
   if(n[2]==u[2]||n[2]==u[2])
   {
       cout << "1";
   }
   else
   {
       cout << "0";
   }
   string jj=n[3],ll=u[3];
   if(jj==ll)
   {
       cout << "1";
   }
   else{
    cout  << "0";
   }
   return 0;
}
