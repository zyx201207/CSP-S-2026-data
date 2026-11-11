#include<bits/stdc++.h>
#define int long long
using namespace std;
int lc_1,ls_1,lc_2,ls_2;
string c_1,s_1,c_2,s_2;
void init()
{
	cin>>c_1>>s_1>>c_2>>s_2;
	lc_1=c_1.size();
	lc_2=c_2.size();
	ls_1=s_1.size();
	ls_2=s_2.size();
	c_1=" "+c_1;
	c_2=" "+c_2;
	s_1=" "+s_1;
	s_2=" "+s_2;
}
void solve()
{
	int flag=0;
	string a="",b="";
	char x=s_1[ls_1],y=s_2[ls_2];
	for(int i=1; i<ls_1; i++)
		a+=s_1[i];
	for(int i=1; i<ls_2; i++)
		b+=s_2[i];
	if(c_1 == c_2 && a == b)
		cout<<1;
	else
		cout<<0;
	if(c_1 == c_2 && a == b)
	{
		if((x >= 'A' && x <= 'C' && y >= 'A' && y <= 'C') || ((x >= 'D' && x <= 'F' && y >= 'D' && y <= 'F')))
		{
			flag=1;
			cout<<1;
		}
		else
			cout<<0;
	}
	else
		cout<<0;
	if(flag)
	{
		if(abs(x-y) == 1)
			cout<<1;
		else
			cout<<0;
	}
	else
		cout<<0;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	init();
	if(c_1 == c_2)
		cout<<1;
	else
		cout<<0;
	solve();
	return 0;
}
