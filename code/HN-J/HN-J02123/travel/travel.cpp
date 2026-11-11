#include<bits/stdc++.h>
#include<string.h>
#include<iostream>
using namespace std;
int const N=1005;
int a[N]; 
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=17;i++)
	{
		if(i==1||i==16)
		c1!=i;
		c2!=i;
	}
	if(c1==c2) cout<<"1";
		else cout<<"0000";
		return 0;
	for(int i=1;i<=18;i++)
	{
		s1=i;
	  for(int j=1;j<=18;j++)
	  {
	  	s2=j;
	  if(i==j)
	  cout<<"1";
	  else cout<<"0";
	  }
	}
	
}
