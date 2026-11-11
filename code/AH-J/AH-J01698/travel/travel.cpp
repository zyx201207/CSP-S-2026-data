//writen by xiong
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a1,a2;
	char b1,b2;
	ll s1,s2;
	cin>>a1>>s1>>b1>>a2>>s2>>b2;
	if(a1==a2)
		cout<<"1";
	else
	{
		cout<<"0000";
		exit(0);
	}
	if(s1==s2)
		cout<<"1";
	else
	{
		cout<<"000";
		exit(0);
	}
	bool f=0;
	if(65<=(int)b1&&(int)b1<=67&&65<=(int)b2&&(int)b2<=67)
	{
		f=1;
		cout<<"1";
	}
	else if(68<=(int)b1&&(int)b1<=70&&68<=(int)b1&&(int)b1<=70)
	{
		f=1;
		cout<<"1";
	}
	else
	{
		cout<<"00";
		exit(0);
	}
	if(abs((int)b1-(int)b2)==1&&f==true)
		cout<<"1";
	else
	{
		if(((int)b1==68&&(int)b2==70)||((int)b2==68&&(int)b1==70))
			cout<<"1";
		else	
			cout<<"0";
	}
	return 0;
}
