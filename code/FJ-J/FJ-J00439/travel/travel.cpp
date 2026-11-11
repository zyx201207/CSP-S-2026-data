#include <bits/stdc++.h>
using namespace std;
int cnt,a,s;
string aa,as,oo,po;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>aa>>as>>oo>>po;
	for(int i=0;i<=1;i++)
	{
		if(aa[i]==oo[i])
		{
			cnt++;
		}
	}
	if(cnt==2)
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
	}
	cnt=0;
	for(int i=0;i<=1;i++)
	{
		if(as[i]==po[i])
		{
			cnt++;
		}
	}
	if(cnt==2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	cnt=0;
	if(as[2]=='A'||as[2]=='B'||as[2]=='C')
	{
		a=1;
	}
	if(po[2]=='A'||po[2]=='B'||po[2]=='C')
	{
		s=1;
	}
	
	if(a==s)
	{
		cout<<1;
		if(a==0)
		{
			cout<<1;
		}
		else
		{
			if(as[2]=='A'&&po[2]=='B')
			{
				cout<<1;
			}
			else if(as[2]=='B'&&po[2]=='C')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
	else
	{
		cout<<0;
		cout<<0;
	}
	
	return 0;
} 
