#include<bits/stdc++.h>
using namespace std;
long long a[200007];
long long cnt = 0;
long long ans = 0;
bool vis[200007];
int n,m;
long long dfs(int x,int zh)
{
	
	if(x >= m || zh >= n)
	{
		vis[zh] = 1;
		return a[zh];
	}
	if(vis[zh + 1] == 0)
	{
		vis[zh + 1] = 1;
		ans = max(dfs(x + 1,zh + 1) & a[zh],ans);
		vis[zh + 1] = 0;
	}
	dfs(x,zh + 1);
}
int main()
{
	
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i <= n - m + 1;i++)
	{
		cnt = max(dfs(1,i),cnt);
		ans = 0;
		memset(vis,0,sizeof(vis));	
	}
	
	cout<<cnt;
	return 0;
	
	
	
}
