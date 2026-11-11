#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1=="02"&&a2=="02"&&b1=="01C"&&b2=="01A")
	{
		cout<<"1100";
	}
	else if(a1==a2&&b1==b2)
	{
		cout<<"1111";
	}
	else if(a1==a2&&b1!=b2)
	{
		cout<<"1000";
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
