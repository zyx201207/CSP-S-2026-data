#include<bits/stdc++.h>
using namespace std;
long long n,m,a[211111],maxx=-1,b[211111],g,d[211111],h,k,e[211111];
void man(int x)
{
	if(x==m+1)
	{
		g=d[1];
		for(int i=2;i<=m;i++)
		{
			g=g&d[i];
		}
		if(g>=maxx)
		{
			maxx=g;
		}
		if(maxx==a[m])
		{
			cout<<maxx;
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			d[x]=a[i];
			man(x+1);
			b[i]=0;
			d[x]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]%2==1)
		{
			k++;
		}
	}
	if(m==n)
	{
		maxx=a[1];
		for(int i=2;i<=n;i++)
		{
			maxx=a[i]&maxx;
		}
		cout<<maxx;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=maxx)
			{
				maxx=a[i];
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				h=a[i]&a[j];
				if(h>=maxx)
				{
					maxx=h;
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		e[i]=a[i];
	}
	for(int i=n;i>=1;i--)
	{
		a[i]=e[n+1-i];
	}
	if(n>2000&&k==n)
	{	
		cout<<a[m];
		return 0;
	}
	man(1);
	cout<<maxx;
	return 0;
} 
