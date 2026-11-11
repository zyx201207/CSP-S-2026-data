#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s=INT_MAX;
long long maxx=-1e9;
bool vis[200005];
void dfs(int u,int cnt,long long sum)
{
	if(u==n+1)
	{
		if(cnt!=m) return ;
		maxx=max(maxx,sum);
		return ;
	}
	vis[u]=1;
	dfs(u+1,cnt+1,sum&a[u]);
	vis[u]=0;
	dfs(u+1,cnt,sum);
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
	dfs(1,0,s);
	cout<<maxx;
	return 0;
}
