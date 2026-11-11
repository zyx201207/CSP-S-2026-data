#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char a1=s1[2],a2=s2[2];
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		cout<<"1"; 
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(a1>='A' && a1<='C' && a2>='A' && a2<='C')
	{
		cout<<"1";
	}
	else if(a1>='F' && a1<='D' && a2>='D' && a2<='F')
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(s1[2]-s2[2]==1)
	{
		cout<<"1";
	}
	else if(s2[2]-s1[2]==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
