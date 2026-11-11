#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int a[N+1];
int ans;
bool cmp(int x,int y)
{
	return x>y;
}
bool vis[N+1];
void dfs(int x,int t,int cnt)
{
	if(cnt==m)
	{
		t=t&a[x];
		ans=max(ans,t);
		return;
	}
	vis[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i,t&a[x],cnt+1);
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		sort(a+1,a+1+n,cmp);
		cout<<a[1];
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
	}else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					int t=a[i]&a[j];
					ans=max(ans,t);
				}
			}
		}
		cout<<ans;
	}else 
	{
		for(int i=1;i<=n;i++)dfs(i,a[i],1);
		cout<<ans;
	}
	return 0;
}
