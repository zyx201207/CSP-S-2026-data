#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,r1,x,x1;
	int ok_1=1,ok_2=1,ok_3=0,ok_4=0;
	cin>>r>>r1>>x>>x1;
	for(int i=0;i<2;i++)
		if(r[i]!=x[i]) 
		{
			cout<<"0000";
			return 0;
		}
	for(int i=0;i<2;i++)
		if(r1[i]!=x1[i]) 
		{
			cout<<1000;
			return 0;
		}
	if((r1[2]<='C'&&x1[2]<='C')||('C'<r1[2]&&r1[2]<='E'&&'C'<x1[2]&&x1[2]<='E')) 
	{
		ok_3=1;
	}
	else
	{
		cout<<1100;
		return 0;
	}
	if(r1[2]+1==x1[2]||r1[2]-1==x1[2])
	{
		ok_4=1;
	}
	else
	{
		cout<<1110;
		return 0;
	}
	cout<<1111;
	return 0;
} 
