#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool fun(char a,char b)
{
	if(a>='A'&&a<='C'&&b>='A'&&b<='C'||(a>='D'&&a<='E'&&b>='D'&&b<='E'))
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F')
	{
		s1[2]='E';
	}
	if(s2[2]=='F')
	{
		s2[2]='E';
	}
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]+s1[1]==s2[0]+s2[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(fun(s1[2],s2[2]))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])<=1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
