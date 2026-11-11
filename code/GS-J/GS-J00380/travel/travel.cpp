#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);   
  char c1[1005],s1[1005],c2[1005],s2[1005];
  cin>>c1[1005]>>s1[1005]>>c2[1005]>>s2[1005];
  if(c1[1]==c2[1])
  {
	cout<<"1";  
   
  }
  else
  {
  	cout<<"0000";
  	return 0;
  }
  if(s1[1]==s2[1]&&s1[2]==s2[2])
  {
 	cout<<"1";
  }
  else
  {
  	cout<<"000";
  	return 0;
  }
  if(s1[3]=='A' && s2[3]=='B' || s1[3]=='B'&& s2[3]=='C')
  {
  	cout<<"1";
  }
   else
  {
  	cout<<"00";
  	return 0;
  }
  if(s2[3]=='A'&&s1[3]=='B'||s2[3]=='B'&&s1[3]=='C')
  {
  	cout<<"1";
  }
   else
  {
  	cout<<"0";
  	return 0;
  }
  return 0;
 }
