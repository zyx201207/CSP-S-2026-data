#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
long long maxx=-1e9;
long long a[200010];
int check(int c,int d)
{
	int a=0,b=0,x=0,y=1,u=0;
	while(c||d)
	{
		a=c%2,b=d%2;
		c/=2,d/=2;
		if(a==b&&a==1)
		{
			x+=y;
//			cout<<"x:"<<x<<endl;
		}
		y*=2;
	}
	return x;
}
void dfs(int u,long long x,int mn)
{
	if(mn>=m)
	{
		maxx=max(maxx,x);
		return;
	}
	sum=x;
	x=check(x,a[u]);
	dfs(u+1,x,mn+1);
	x=sum;
	dfs(u+1,x,mn);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long aa=check(a[i],a[j]);
				maxx=max(maxx,aa);
			}
		}
	}
	else if(n==m)
	{
		maxx=a[1];
		for(int i=2;i<=n;i++)
		{
			maxx=check(maxx,a[i]);
		}
	}
	else dfs(0,0,0);
//	maxx=check(3,15);
	cout<<maxx;
	return 0;
}
