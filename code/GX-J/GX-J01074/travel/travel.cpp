#include<bits/stdc++.h>
using namespace std;
int n,n1;
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  string c1,s1,c2,s2;
  cin>>c1>>s1>>c2>>s2;
  for(int i=0;i<2;i++)
  {
    if(c1[i]==c2[i])
    {
        n++;
    }
  }
  if(n!=2)
  {
      cout<<0<<0<<0<<0;return 0;
  }
  else
  {
      cout<<1;
      for(int i=0;i<2;i++)
      {
          if(s1[i]==s2[i])
          {
              n1++;
          }
      }
      if(n1!=2)
      {
          cout<<0<<0<<0;return 0;
      }
      else
      {
          cout<<1;
          if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A')
          {
              cout<<1<<0;return 0;
          }
          if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D')
          {
              cout<<1<<1;return 0;
          }
          else
          {
              cout<<0<<0;return 0;
          }
      }
  }
  return 0;
}
