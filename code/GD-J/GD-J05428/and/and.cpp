#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int ans=-1e9;
bool fl=1;
void dfs(int h,int sum,int cnt)
{
	if(h>n)
	{
		if(cnt==m)
		{
			ans=max(ans,sum);
		}
		return ;
	}
	if(cnt==0)
	{
		dfs(h+1,a[h],cnt+1);
		dfs(h+1,sum,cnt);
		return ;
	}
	dfs(h+1,(sum&a[h]),cnt+1);
	dfs(h+1,sum,cnt);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		dfs(1,-1,0);
		cout<<ans;
	}
	else if(m==n)
	{
		int sum=a[1];
		for(int i=1;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
	}
	else if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2)
	{
		cout<<(a[n]&a[n-1]);
	}
}
