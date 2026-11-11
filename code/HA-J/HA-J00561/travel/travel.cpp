#include<bits/stdc++.h>
using namespace std;

const int N=1e2+5;
struct ly
{
	int cx;
	string zw;
}a[N];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int x=1,r=2;
	cin>>a[x].cx;
	cin>>a[x].zw;
	cin>>a[r].cx;
	cin>>a[r].zw;
	
	int pd=0;
	if(a[x].cx==a[r].cx)
	{
		cout<<1;
		pd++;
	}
	else
	{
		pd=0;
		cout<<"0000";
		return 0;
	}
	
	int x1,r1;
	x1=a[x].zw[0]-'0'*10+a[x].zw[1]-'0';
	r1=a[r].zw[0]-'0'*10+a[r].zw[1]-'0';
	if(x1==r1)
	{
		cout<<1;
		pd++;
	}
	
	char x2,r2;
	x2=a[x].zw[2];
	r2=a[r].zw[2];
	if(x2=='A' && r2=='B' || x2=='B' && r2=='C' || x2=='D' && r2=='F')
	{
		cout<<11;
		pd+=2;
	}
	if(r2=='A' && x2=='B' || r2=='B' && x2=='C' || r2=='D' && x2=='F')
	{
		cout<<11;
		pd+=2;
	}
	
	if(pd==1)
	{
		cout<<"000";
	}
	if(pd==2)
	{
		cout<<"00";
	}
	if(pd==3)
	{
		cout<<0;
	}
	return 0;
}
