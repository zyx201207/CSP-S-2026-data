#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a,b;
char a1,a2,a3;
char b1,b2,b3;
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>a1>>a2>>a3;
	cin>>b>>b1>>b2>>b3;
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if((a1==b1)&&(a2==b2))
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((a3>='D')&&(b3>='D'))
	{
		cout<<"11";
		return 0;
	}
	else if((a3<='C')&&(b3<='C'))
	{
		cout<<1;
		if((char(a3+1)==b3)||((a3-1)==b3))
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		cout<<"00";
		return 0;
	}
	return 0;
}
