#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool vis[200005];
void dfs(int x,int y,int z)
{
	vis[x]=1;
	z=(z&a[x]);
	if(y==m) 
	{
		ans=max(ans,z);
		return;
	}
	for(int i=1;i<n;i++)
	{
		if(!vis[i]) dfs(i,y+1,z);
	}
	vis[x]=0;
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
	for(int i=1;i<=n;i++)
	{
		dfs(i,1,a[i]);
	}
	cout<<ans;
 } 
