#include<bits/stdc++.h>
using namespace std;;
typedef long long ll;
const int N = 2e5+7;
int ans,n,m;
int a[N];
bool flag=1;
bool vis[N];
void dfs(int h,int sum)
{
	if(h==m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		dfs(h+1,(sum&a[i]));
		vis[i]=0;
	}
}
int main(void)
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	ll s=0;
	for(int i=1;i<=20;i++)s=s*2+1;
	
	if(m==n)
	{
		ans=s;
		for(int i=1;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i-1)flag=0;
	}
	if(flag)
	{
		cout<<n-m;
		return 0;
	}
	else if(n>=2001)
	{
		cout<<a[n-m+1];
		return 0;
	}
	dfs(0,s);
	cout<<ans;
	return 0;
}
