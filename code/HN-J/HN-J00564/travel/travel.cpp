#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct N{
	int sz;
	string zw;
}; 
N a[10], b[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s, n;
	cin>>a[1].sz>>a[2].zw>>b[1].sz>>b[2].zw;
	if(a[1].sz==b[1].sz)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	s=a[2].zw;
	n=b[2].zw;
	if(s[1]==n[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((s[2]>='A'&&s[2]<='C')&&(n[2]>='A'&&n[2]<='C'))
	{
		cout<<"1";
	}
	else if((s[2]>='D'&&s[2]<='F')&&(n[2]>='D'&&n[2]<='F'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((s[2]>='A'&&s[2]<='C')&&(n[2]>='A'&&n[2]<='C'))
	{
		if(s[2]+1==n[2]||s[2]-1==n[2])
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	else if((s[2]>='D'&&s[2]<='F')&&(n[2]>='D'&&n[2]<='F'))
	{
		cout<<"1";
		return 0;
	}
	else
	{
		cout<<"0";
		return 0;
	}
	return	0;
} 
