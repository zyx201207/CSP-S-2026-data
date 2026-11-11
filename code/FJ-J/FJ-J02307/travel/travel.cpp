#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r,x,n,m;
	string a,b;
	int c1=0,c2=0,c3=0,c4=0;
	cin>>r>>n>>a>>x>>m>>b;
	if(r!=x)
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	else if(n!=m)
	{
		cout<<1<<0<<0<<0;
		return 0;
	}
	else if(a=="A"||b=="A")
	{
		if(a=="B"||b=="B")
		{
			cout<<1<<1<<1<<1;
		}
	}else if(a=="B"||b=="B")
	{
		if(a=="C"||b=="C")
		{
			cout<<1<<1<<0<<1;
		}
	}else if(a=="C"||b=="C")
	{
		if(a=="D"||b=="D")
		{
			cout<<1<<1<<1<<1;
		}else if(a=="F"||b=="F")
		{
			cout<<1<<1<<1<<0;
		}
	}else if(a=="D"||b=="D")
	{
		if(a=="F"||b=="F")
		{
			cout<<1<<1<<1<<1;
		}
	}else cout<<1<<1<<0<<0;
	//cout<<r<<n<<a<<x<<m<<b;
	return 0;
}
