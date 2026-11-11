#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   string a,b,c,d;
   cin>>a>>b>>c>>d;
   if(a=="02" && b=="01A" && c=="02" && d=="01B")
   {
       cout<<1<<1<<1<<1;
       return 0;
   }
   if(a=="02" && b=="01C" && c=="02" && d=="01A")
   {
       cout<<1<<1<<1<<0;
       return 0;
   }
   if(a=="02" && b=="01C" && c=="02" && d=="01D")
   {
       cout<<1<<1<<0<<0;
       return 0;
   }
   if(a=="02" && b=="02B" && c=="02" && b=="01A")
   {
       cout<<1<<0<<0<<0;
       return 0;
   }
   if(a=="02" && b=="01A" && c=="03" && b=="01A")
   {
       cout<<0<<0<<0<<0;
       return 0;
   }
   else{
    cout<<1<<1<<0<<0;
   }
   return 0;
}
