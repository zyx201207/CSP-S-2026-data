#include<bits/stdc++.h>
using namespace std;
int main()
{freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
 int c1,c2,b1,b2,l;
 char s1[3],s2[3];
 cin>>c1>>s1>>c2>>s2;
 b1=int(s1[2]);
 b2=int(s2[2]);
 if(c1==c2)
 {cout<<1;
  if(s1[0]==s2[0]&&s1[1]==s2[1])
  {cout<<1;
   if((b1>=68&&b2>=68)||(b1<=67&&b2<=67))
   {cout<<1;
    l=b1-b2;
    if(l<0)
    l=l*(-1);
    if(l==1)
    cout<<1;
    else
    cout<<0;
   }
   else
   cout<<0<<0;
  }
  else
  cout<<0<<0<<0;
 }
 else
 cout<<0<<0<<0<<0; 
 return 0;
}
