#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a1,a2;
	string b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1])
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(a2[2]<='C'&&b2[2]<='C')
		cout<<1;
	else if(a2[2]>='D'&&b2[2]>='D')
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(a2[2]-1==b2[2]||b2[2]-1==a2[2])
		cout<<1;
	else if(a2[2]=='D'||a2[2]=='F')
	{
		if(a2[2]=='D'||a2[2]=='F') 
			cout<<1;
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		cout<<0;
		return 0;
	}
	return 0;
}
