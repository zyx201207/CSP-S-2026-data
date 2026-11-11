#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool solve(char c)
{
	if(c=='D'||c=='F')
	return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a[0]!=b[0]||a[1]!=b[1])
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(c[0]==d[0]&&c[1]==d[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(solve(c[2])==solve(d[2]))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(max(c[2],d[2])-1==min(c[2],d[2]))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
