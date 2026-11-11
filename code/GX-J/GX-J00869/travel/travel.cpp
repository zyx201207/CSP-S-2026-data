#include<bits/stdc++.h>
using namespace std;
string a[55]={"01A","01B","01C","02A","02B","02C","03A","03B","03C","04A","04B","04C","05A","05B","05C","06A","06B","06C",
			 "07A","07B","07C","08A","08B","08C","09A","09B","09C","10A","10B","10C","11A","11B","11C","12A","12B","12C",
			 "13A","13B","13C","14A","14B","14C","15A","15B","16C","16A","16B","16C","17A","17B","17C","18A","18B","18C"};
string b[37]={"01D","01F","02D","02F","03D","03F","04D","04F","05D","05F","06D","06F","07D","07F","08D","08F","09D","09F",
			 "10D","10F","11D","11F","12D","12F","13D","13F","14D","14F","15D","15F","16D","16F","17D","17F","18D","18F"};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=0,m=0,x=0,y=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<55;i++)
	{
		if(s1==a[i])
		{
			n=1;
			x=i/3;
			break;
		}
	}
	for(int i=0;i<55;i++)
	{
		if(s2==a[i])
		{
			m=1;
			y=i/3;
			break;
		}
	}
	if(x==0)
	{
		for(int i=0;i<37;i++)
		{
			if(s1==b[i])
			{
				x=i/2;
				break;
			}
		}
	}
	if(y==0)
	{
		for(int i=0;i<37;i++)
		{
			if(s1==b[i])
			{
				y=i/2;
				break;
			}
		}
	}
	if(x==y) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(n==m) cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	for(int i=0;i<55;i++)
	{
		if(s1==a[i])
		{
			if(s2==a[i+1] || s2==a[i-1])
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
	}
	for(int i=0;i<37;i++)
	{
		if(s1==b[i])
		{
			if(s2==b[i+1] || s2==b[i-1])
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
	}
	return 0;
}
