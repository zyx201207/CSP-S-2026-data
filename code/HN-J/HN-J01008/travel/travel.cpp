#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n1,n2,p1,p2;
	cin>>n1>>p1>>n2>>p2;
	if(n1==n2)
	{
		cout<<"1111";
		return 0;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(p1==p2)
	{
		cout<<"111";
		return 0;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	return 0;
}
