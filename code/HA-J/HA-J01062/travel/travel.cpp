#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	char x='1',y='0';
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<x;
	}
	else
	{
		cout<<y<<y<<y<<y;
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1])
	{
		cout<<x;
	}
	else
	{
		cout<<y<<y<<y;
		return 0;
	}
	
		if(a2[2]<='C'&&b2[2]<='C')
		{
			cout<<x;
		}
		else if(a2[2]>'C'&&b2[2]>'C')
		{
			cout<<x;
		}
		else
		{
			cout<<y<<y;
			return 0;
		}
	if(a2[2]-1==b2[2]||a2[2]+1==b2[2])
	{
		cout<<x;
	}
	else
	{
		cout<<y;
	}
	return 0;
}
