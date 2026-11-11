#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  cin>>a>>b>>c>>d;
  if(a[0]-'0'==c[0]-'0'&&a[1]-'0'==c[1]-'0')
    cout<<1;
  else
  {
    cout<<0<<0<<0<<0;
    return 0;
  }
  
  if(b[0]-'0'==d[0]-'0'&&b[1]-'0'==d[1]-'0')
    cout<<1;
  else
  {
    cout<<0<<0<<0;
    return 0;
  }
  
  int s=0;
  if(b[2]-'0'>=17&&b[2]-'0'<=19&&d[2]-'0'>=17&&d[2]-'0'<=19)
  {
    cout<<1;
    s++;
  }
  else if(b[2]-'0'>=20&&b[2]-'0'<=21&&d[2]-'0'>=20&&d[2]-'0'<=21)
  {
    cout<<1;
    s++;
  }
  if(s==0)
  {
    cout<<0<<0;
    return 0;
  }
  
  int x1=d[2]-'0'-1,x2=d[2]-'0'+1;
  if(b[2]-'0'==x1||b[2]-'0'==x2)
    cout<<1;
  else
    cout<<0;
  return 0;
}
