#include<bits/stdc++.h>
using namespace std;
string x,y,s1,s2;
bool check(char a,char b)
{
	if (a<='C' && b<='C')
	{
		return 1;
	}
	if (a>='D' && b>='D')
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>x;
	cin>>s1;
	cin>>y;
	cin>>s2;
	bool flag=0;
	string ans="";
	if (x==y)
	{
		flag=1;
		ans+='1';
	}
	else
	{
		flag=0;
		ans+='0';
	}
	if (flag==1 && s1[0]==s2[0] && s1[1]==s2[1])
	{
		flag=1;
		ans+='1';
	}
	else
	{
		flag=0;
		ans+='0';
	}
	if (flag==1 && check(s1[2],s2[2])==1)
	{
		flag=1;
		ans+='1';
	}
	else
	{
		flag=0;
		ans+='0';
	}
	if (flag==1 && abs(s1[2]-s2[2])==1)
	{
		ans+='1';
	}
	else
	{
		ans+='0';
	}
	cout<<ans;
	return 0;
}
