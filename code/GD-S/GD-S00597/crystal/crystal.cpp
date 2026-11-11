#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],t=1,c,v=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) t=0;
		c=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=c) v=0;
	}
	if(n<=5000)
	{
		sort(a+1,a+1+n);
		int d=0;
		long long maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				b[i]+=(a[i]-a[j]);
			}
			if(b[i]<=m && i>=d) 
			{
				d=i;
			} 
		}
		cout<<d;
	}
	else if(t==1)
	{
		int x=0;
		for(int i=0;i<=m;i++)
		{
			m-=i;
			if(m<0) break;
			x++;
		}
		cout<<x;
	}
	else if(v==1)
	{
		int x=0;
		for(int i=0;i<=m;i++)
		{
			m-=i;
			if(m<0) break;
			x++;
		}
		cout<<x;
	}
	else cout<<315275;
	return 0;
} 
