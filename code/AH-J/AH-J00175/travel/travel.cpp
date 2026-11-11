#include <bits/stdc++.h>
using namespace std;
int a,b;
string st,st1;
int main()
{
   freopen ("travel.in","r",stdin);
   freopen ("travel.out","w",stdout);
   cin>>a>>st>>b>>st1;
  if(a==b)cout<<'1';
  else return cout<<"0000",0;
  
   if(st[1]==st1[1] and st[0]==st1[0])cout<<'1';
  else return cout<<"000",0;
  
  if(st[2]=='D' or st[2]=='F' and st1[2]=='D' or st1[2]=='F' and abs(st[2]-st1[2]==1))cout<<"11";
  if(st[2]=='A' or st[2]=='B' or st[2]=='C' and st1[2]=='B' or st1[2]=='C' or st1[2]=='A')
  {
   if(abs(st[2]-st1[2])==1 or abs(st[2]-st1[2])==2)cout<<'1';
   else cout<<'0';
  }
  
  if(st[2]=='A' or st[2]=='B' or st[2]=='C' and st1[2]=='B' or st1[2]=='C' or st1[2]=='A')
  {
   if(abs(st[2]-st1[2])==1)cout<<'1';
   else cout<<'0';
  }
  return 0;
  }
