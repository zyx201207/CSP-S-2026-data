#include<bits/stdc++.h>
using namespace std;
int n,m,ans,vis[200010];
long long a[200010];
void dfs(int x,int p,int l)
{
	if(l==m)
	{
		ans=max(ans,p);
		return;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(p==0)
		{
			dfs(i,a[i],l+1);
		}
		else
		{
			if((p&a[i]<=ans))
				continue;
			dfs(i,(p&a[i]),l+1);
		}
	}
	return;
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
	dfs(0,0,0);
	cout<<ans;
	return 0;
 }
