#include<bits/stdc++.h>
using namespace std;
struct node
{
	string id;
	string seat;
}a[2];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0].id>>a[0].seat;
	cin>>a[1].id>>a[1].seat;
	if(a[0].id!=a[1].id)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(a[0].seat.substr(0,2)!=a[1].seat.substr(0,2))
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((a[0].seat[2]>='D')!=(a[1].seat[2]>='D'))
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(a[0].seat[2]-a[1].seat[2])!=1)
	{
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
}
