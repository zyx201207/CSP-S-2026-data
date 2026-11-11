#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout); 
  ios::sync_with_stdio(false);
  cin.tie(0);
  string c1,s1,c2,s2;
  bool a=0,b=0,c=0,d=0;
  cin>>c1>>s1>>c2>>s2;
  if(c1!=c2)
  {
  	cout<<"0000";
  	return 0;
  }
  else
    a=1;
  if(s1[0]==s2[0]&&s1[1]==s2[1])
  	b=1;
  if(b==1&&((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')))
    c=1;
  if(c==1&&((s1[2]=='D'&&s2[2]=='F')||(abs(s1[2]-s2[2])==1)))
    d=1;
  cout<<a<<b<<c<<d;
  return 0;
} 
