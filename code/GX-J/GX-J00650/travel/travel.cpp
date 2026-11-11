#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
 {
     freopen("travel.in","r",stdin);
     freopen("travel.out","w",stdout);
     cin >> a>>b>>c>>d;
     if(a==c)
     {
         cout<<"1";
     }
     else
     {
         cout<<"0";
     }
     if(b.size()==d.size())
     {
         cout<<"1"<<"0"<<"1";
     }
     else
     {
         cout<<"1"<<"1"<<"1";
     }
     return 0;
 }
