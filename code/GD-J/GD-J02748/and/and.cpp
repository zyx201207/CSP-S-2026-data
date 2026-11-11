#include <bits/stdc++.h> 
using namespace std;
int n,m,a[200005],ans,vis[200005];
void dfs(int cnt,int sum)
{
	if(cnt==m) 
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++) 
	{
		if(vis[i]==1) continue;
		vis[i]=1;
		if(sum!=0) dfs(cnt+1,sum&a[i]);
		else dfs(cnt+1,a[i]);
		vis[i]=0;
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
	}
	if(m==n) 
	{
		int ansd=a[1];
		for(int i=2;i<=n;i++) 
		{
			ansd&=a[i];
		}
		cout<<ansd;
		return 0;
	}
	if(n<=2000) 
	{
		dfs(0,0);
		cout<<ans;
		return 0;
	}
	else 
	{
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		{
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}

