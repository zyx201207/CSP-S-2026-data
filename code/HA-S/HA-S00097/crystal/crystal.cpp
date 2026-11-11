#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,b,p=999999999999,h=0,l=0;
	cin>>n>>m;

	long long a[n+1],y[n+1];
	for(int i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}
	int o[n+1];
	for(int i=0;i<=n/2;i++)
	{
		for(int t=i;t<=n-1;t++)
		{
			if(a[t]<=p)
			{
				p=a[t];
				h=t;
			}
			
		}
		l=a[h];
		a[h]=a[i];
		a[i]=l;
		p=999999999999999;
	}
	int u=a[n/2];
	for(int i=0;i<=n-1;i++)
	{
		if(a[i]-u<=0)
		{
			y[i]=-(a[i]-u);
		}
		else
		{
			y[i]=a[i]-u;
		}
		
	}
	for(int i=0;i<=n/2;i++)
	{
		for(int t=i;t<=n-1;t++)
		{
			if(y[t]<=p)
			{
				p=y[t];
				h=t;
			}
			
		}
		l=y[h];
		y[h]=y[i];
		y[i]=l;
		p=999999999999999;
	}
	int e=0;
	for(int i=0;i<=n-1;i++)
	{
		if(m>=y[i])
		{
			m-=y[i];
			e++;
		}
	}
	cout<<e;
	
	
	
	
	
	return 0;
	
 } 
