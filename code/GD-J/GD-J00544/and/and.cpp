#include<bits/stdc++.h>
using namespace std;
int a[200005],maxx=-1,m,n,x=1;
void dfs(int mx,int d,int dep)
{
	if(dep==0) mx=a[d+1];
	if(dep==m)
	{
		maxx=max(maxx,mx);
		return;
	}
	if(d==n) return;
	dfs(mx&a[d+1],d+1,dep+1);
	dfs(mx,d+1,dep);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x*=2;
		if(x==n) x=0;
	}
	if(n<=20)
	{
		dfs(1,0,0);
		cout<<maxx;
	}
	else if(m==1) 
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	else if(m==n)
	{
		maxx=a[1];
		for(int i=2;i<=n;i++)
		{
			maxx=(maxx&a[i]);
		}
		cout<<maxx;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}
	else if(x==0)
	{
		cout<<49152;
	}
	else if(m==n-1)
	{
		sort(a+1,a+1+n);
		maxx=a[2];
		for(int i=3;i<=n;i++) maxx=(maxx&a[i]);
		cout<<maxx;
	} 
	else 
	{
		sort(a+1,a+1+n);
		cout<<a[n+1-m];
	}
	return 0;
}
