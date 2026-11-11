#include<bits/stdc++.h>
using namespace std;
char a1[2],b1[3],a2[2],b2[3];
int main()
{

  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
   for(int i=1;i<=2;i++)
   {
       cin>>a1[i];
   }
   for(int i=1;i<=3;i++)
   {
       cin>>b1[i];
   }
    for(int i=1;i<=2;i++)
   {
       cin>>a2[i];
   }
    for(int i=1;i<=3;i++)
   {
       cin>>b2[i];
   }
   if(a1[1]==b1[1]&&a1[2]==b1[2])
   {
   cout<<1;
   }
   else cout<<0;
   if(b1[1]==b2[1]&&b1[2]==b2[2])
   {
   cout<<1;
   }
   else cout<<0;
   if(b1[3]>='A'&&b[3]<='C'&&b2[3]>='A'&&b1[3]<='C'||b1[3]>='D'&&b[3]<='E'&&b2[3]>='D'&&b1[3]<='E')
   {
      cout<<1;
   }
   else cout<<0;
   if(b1[3]+1==b2[3]||b1[3]-1==b2[3])
   {
   cout<1;
   }
   else cout<<0;
   return 0;
}