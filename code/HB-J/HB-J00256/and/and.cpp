#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=0;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int x,int s,int ans)
{
	if(x==m)
	{
		maxn=max(maxn,ans);
		return ;
	}
	for(int i=s+1;i<=n;i++)
	{
		int p=ans & a[i];
		dfs(x+1,i,p);
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int u=a[i];
		while(u)
		{
			if(u%2==0)u/=2;
			else
			{
				flag=0;
				break;
			}
		}
	}
	if(flag)
	{
		maxn=2147483647;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++)
		{
			maxn=maxn&a[i];
		}
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
	}
	if(m==n)
	{
		maxn=2147483647;
		for(int i=1;i<=n;i++)
		{
			maxn=maxn&a[i];
		}
	}
	else
	{
		dfs(0,0,2147483647);
	}
	
	cout<<maxn;
	return 0;
}
