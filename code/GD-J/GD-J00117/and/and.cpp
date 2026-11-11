#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int t[200005];
int ans;
void dfs(int dep,int x,int sum)
{
	if(x>m)
	{
		ans=max(ans,sum);
		return ;
	}
	if(dep>n)
	{
		return ;
	}
	else
	{
		if(x<=m)
		{
			t[x]=a[dep];
			dfs(dep+1,x+1,(sum==-1)?a[dep]:(sum&a[dep]));
		}
		dfs(dep+1,x,sum);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n<=20)
	{
		dfs(1,1,-1);
	}
	else if(n<=2000)
	{
		if(m==1)
		{
			for(int i=1;i<=n;i++)
			{
				ans=max(ans,a[i]);
			}
		}
		else if(m==n)
		{
			for(int i=1;i<=n;i++)
			{
				ans=(i==1)?a[i]:(ans&a[i]);
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j)
					{
						ans=max(ans,a[i]&a[j]);
					}
				}
			}
		}
	}
	else
	{
		sort(a+1,a+1+n);
		ans=a[n-m+1];
	}
	printf("%d",ans);
	return 0;
}
