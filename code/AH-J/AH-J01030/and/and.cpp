#include<bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005];
int w[30];
int ans=0;
int n,m;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x)
{
	if(x==n+1)
	{
		int sum=2147483647; 
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(w[i])
				sum=sum&a[i];
			cnt+=w[i];
		}
		if(cnt==m)
		{
			ans=max(ans,sum);
		}
		return ;
	}
	w[x]=1;
	dfs(x+1);
	w[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int flag=0; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i-1)
			flag=1;
	}
	if(n<=20)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(n<=2000)
	{
		if(m==n)
		{
			int x=a[1];
			for(int i=2;i<=n;i++)
				x=x&a[i];
			cout<<x;
		}
		else if(m==1)
		{
			int x=0;
			for(int i=1;i<=n;i++)
				x=max(x,a[i]);
			cout<<x;
		}
		else
		{
			int x=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					x=max(x,a[i]&a[j]);
			cout<<x;
		}
	}
	else if(!flag)
	{
		int cnt=0,ans=2147483647;
		for(int i=n;i>=1;i--)
		{
			int x=ans&a[i];
			if(x==0)
				continue;
			cnt++;
			ans=ans&a[i];
			if(cnt==m)
				break;
		} 
		if(cnt==m)
			cout<<ans;
		else
			cout<<0;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0;
}
