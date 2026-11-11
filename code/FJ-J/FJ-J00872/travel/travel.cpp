#include<bits/stdc++.h>
using namespace std;
struct p{
	string c,s;//c³µÏáºÅ£¬s×ùÎ»ºÅ 
};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	p r,x;
	cin>>r.c>>r.s>>x.c>>x.s;
	if(r.c==x.c)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(r.s[0]==x.s[0]&&r.s[1]==x.s[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(((r.s[2]>='A'&&r.s[2]<='C')&&(x.s[2]>='A'&&x.s[2]<='C'))||((r.s[2]>='D'&&r.s[2]<='F')&&(x.s[2]>='D'&&x.s[2]<='F')))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(int(r.s[2])-int(x.s[2]))==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
}
