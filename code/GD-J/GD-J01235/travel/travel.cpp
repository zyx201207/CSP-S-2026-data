#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,a2,b2;
	cin>>a>>b>>a2>>b2;
	if(a==a2)
	{
		cout<<1<<' ';
	}
	else
	{
		cout<<0<<' '<<0<<' '<<0<<' '<<0;
		return 0;
	}
	if(b[0]==b2[0]&&b[1]==b2[1])
	{
		cout<<1<<' ';
	}
	else
	{
		cout<<0<<' '<<0<<' '<<0;
		return 0;
	}
	if((b[2]>='D'&&b2[2]>='D')||(b[2]<'D'&&b2[2]<'D'))
	{
		cout<<1<<' ';
	}
	else
	{
		cout<<0<<' '<<0;
		return 0;
	}
	if(b[2]-1==b2[2]||b[2]+1==b2[2]||(b[2]=='D'&&b2[2]=='F')||(b[2]=='F'&&b2[2]=='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
