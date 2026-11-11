#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(a2[0]==b2[0]&&a2[1]==b2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(a2[2]<='C'&&b2[2]<='C')
	{
		cout<<1;
		if(abs(a2[2]-b2[2])==1)
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
		}
	}
	else if(a2[2]>='D'&&b2[2]>='D')
	{
		cout<<1;
		if(abs(a2[2]-b2[2])==2)
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
		}
	}
	else
	{
		cout<<"00";
	}
	return 0;
}
