#include<bits/stdc++.h>
using namespace std;
long long a[500005],f[500005],g[500005],p[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,i,j,t=1;
	int d=1,e=1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		   d=0;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			e=0;
		}
	}
	if(d==1)
	{
		//g[0]=-1;
		for(i=1;i<=n;i++)
		{
			g[i]=g[i-1]+i-1;
			if(g[i]+i>m)
			{
				cout<<i;
				return 0;
			}
		}
		
	}
	if(e==1)
	{
		int u=a[2]-a[1];
		//g[0]=-1;
		for(i=1;i<=n;i++)
		{
			g[i]=g[i-1]+(i-1)*u;
			if(g[i]+i*u>m)
			{
				cout<<i;
				return 0;
			}
		}
		
	}
	sort(a+1,a+n+1);
	f[1]=1;
	g[1]=0;
	
	for(i=2;i<=n;i++)
	{
		//cout<<i;
		g[i]=g[i-1]+f[i-1]*(a[i]-a[i-1]);
		if(g[i]<=m)
		{
			f[i]=f[i-1]+1;
		}
		else 
		{
			f[i]=f[i-1]+1;
			for(j=t;j<=i;j++)
			{
				g[i]=g[i]-(a[i]-a[j]);
				f[i]=f[i]-1;
				if(g[i]<=m)
				{
					t=j+1;
				   	break;
				}
				
			}
		}
	}
	long long max1=0;
	for(i=1;i<=n;i++)
	{
		max1=max(max1,f[i]);
		//cout<<f[i]<<"  ";
	}
	cout<<max1;
	return 0;
	/*
	5 5
	1 2 4 8 9
	10 8
	-3 -1 2 2 7 9 11 13 15 16
	*/
}
