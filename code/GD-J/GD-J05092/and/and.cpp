#include<bits/stdc++.h> 
using namespace std;
int n,m;
int ans;
int a[200007],t[200007];
bool vis[200007];
int sum=0;
void dfs(int st)
{
	if (st>m)
	{
		for (int i=1;i<=m;i++)
		{
			sum^=a[t[i]];
		}
		ans=max(sum,ans);
		return ;
	}
	for (int i=t[st-1]+1;i<=n;i++)
	{
		if (!vis[i])
		{
			vis[i]=1;
			t[st]=i;
			dfs(st+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
