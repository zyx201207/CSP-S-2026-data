#include<bits/stdc++.h>
using namespace std;
int a[5];
char b[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1];
	cin>>a[2]>>b[1];
	cin>>a[3];
	cin>>a[4]>>b[2];
	if(a[1]!=a[3])
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(a[2]==a[4])
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((b[1]<='C'&&b[2]<='C')||(b[1]>='D'&&b[2]>='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(b[1]-b[2])==1||(b[1]>='D'&&b[2]>='D'))
	cout<<1;
	else
	cout<<0;
	return 0;
} 
