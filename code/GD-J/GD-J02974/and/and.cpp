#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[231452];
int ans=0;
void dfs(int k,int cnt,int h)
{
	if(cnt==m)
	{
		ans=max(ans,h);
		return;
	}
	if(k>n)
	{
		return;
	}
	if(h<ans)
	{
		return;
	}
	dfs(k+1,cnt,h);
	dfs(k+1,cnt+1,h&a[k]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i+1,1,a[i]);
	}
	cout<<ans;
}
