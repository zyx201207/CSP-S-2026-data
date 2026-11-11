#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char _1,_2,_3,_4,s1,s2;
	short a,b,c,d;
	cin>>_1>>a>>_2>>b>>s1>>_3>>c>>_4>>d>>s2;
	if(_1=='1') a+=10;
	if(_2=='1') b+=10;
	if(_3=='1') c+=10;
	if(_4=='1') d+=10;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	if(b!=d)
	{
		cout<<"1000";
		return 0;
	}
	if((s1=='D'&&s2=='F')||(s1=='F'&&s2=='D'))
	{
		cout<<"1111";
		return 0;
	}
	if(s1=='A')
	{
		if(s2=='B') cout<<"1111";
		else if(s2=='C') cout<<"1110";
		else cout<<"1100";
		return 0;
	}
	if(s1=='B')
	{
		if(s2=='A'||s2=='C') cout<<"1111";
		else cout<<"1100";
		return 0;
	}
	if(s1=='C')
	{
		if(s2=='B') cout<<"1111";
		else if(s2=='A') cout<<"1110";
		else cout<<"1100";
		return 0;
	}
	if(s1=='D')
	{
		if(s2=='F') cout<<"1111";
		else cout<<"1100";
		return 0;
	}
	if(s1=='F')
	{
		if(s2=='D') cout<<"1111";
		else cout<<"1100";
		return 0;
	}
	return 0;
}
