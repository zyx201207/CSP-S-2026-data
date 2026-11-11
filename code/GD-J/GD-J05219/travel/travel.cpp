#include<bits/stdc++.h>

using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a!=b)
	{
		cout<<0000;
	}
	else if(!(a1[0]==b1[0]&&a1[1]==b1[1]))
	{
		cout<<1000;
	}
	else if(a1[2]=='D'&&b1[2]=='F'||a1[2]=='F'&&b1[2]=='D')
	{
		cout<<1111;
	}
	else if((a1[2]=='A'&&b1[2]=='C')||(a1[2]=='C'&&b1[2]=='A'))
	{
		cout<<1110;
	}
	else
	{
		cout<<1111;
	}
	return 0;
 } 
