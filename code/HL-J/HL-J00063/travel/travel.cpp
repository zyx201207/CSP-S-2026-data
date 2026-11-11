#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2,m=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	} 
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	
	
	char a1=s1[0],b1=s2[0],a2=s1[1],b2=s2[1],a3=s1[2],b3=s2[2];
	if(a1==b1 && a2==b2)
		cout<<1;
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	
	
	
	if(a3=='A')
	{
		if(b3=='C' || b3=='B')
		{
			cout<<1;
			m=1;
		}
	}
	else if(a3=='B')
	{
		if(b3=='A' || b3=='C')
		{
			cout<<1;
			m=1;
		}
	}
	else if(a3=='C')
	{
		if(b3=='A' || b3=='B')
		{
			cout<<1;
			m=1;
		}
	}
	else if(a3=='D' && b3=='F' || a3=='F' && b3=='D')
	{
		cout<<1;
		m=1;
	}
	if(m==0)
	{
		cout<<0<<0;
		return 0;
	}
	
	
	
	if(a3=='A' && b3=='B' || a3=='B' && b3=='C' || a3=='B' && b3=='A' || a3=='C' && b3=='B' || a3=='D' && b3=='F' || a3=='F' && b3=='D')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
