#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool f[20];
long long n,m,ans;
void dfs(long long t,long long u,long long tt)
{
	if(t==n and tt==m)
	{
		ans=max(ans,u);
		
		return ;
	}
	else if(t==n)
	{
		u=0;
		t=0;
		tt=0;
		return ;
	}
	else
	{
		dfs(t+1,u,tt);
		if(tt==0)
		{
			u=a[t];
			dfs(t+1,u,tt+1);
		}
		else dfs(t+1,u&a[t],tt+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		dfs(0,0,0);
	}
	else if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	else if(m==n)
	{
		ans=a[0];
		for(int i=1;i<n;i++)
		{
			ans=a[i]&ans;
		}
	}
	else if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else if(m==n-1)
	{
		int m=a[0];
		for(int i=1;i<n;i++)
		{
			m=m&a[i];
		}
		for(int i=0;i<n;i++)
		{
			if((m&a[i])>ans)
			{
				ans=m&a[i];
			}
		}
	}
	else
	{
		sort(a,a+n);
		ans=a[m-1];
	}
	cout<<ans;
 } 
