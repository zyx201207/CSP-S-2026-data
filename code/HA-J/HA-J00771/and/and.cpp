#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[214514];
int b[214514];
bool vis[31451440];
int maxx =0;
void dfs(int x)
{
	if(x==m+1)
	{
		int ans =b[1];
		for(int i=2;i<=m;i++)
		{
			ans &= b[i];
		}
		maxx = max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[a[i]])
		{
			b[x] = a[i];
			vis[a[i]]=1;
			dfs(x+1);
			vis[a[i]]=0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<maxx;
}