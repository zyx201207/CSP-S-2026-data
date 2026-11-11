#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n,m;
int ans=0;
void dfs(int x,int y,int cnt)
{
	if(x>n) return;
	if(cnt==m)
	
	{
	ans=max(ans,y);
		return;
	}
	dfs(x+1,y&a[x],cnt+1);
	dfs(x+1,y,cnt);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	cin>>a[i];
	for(int i=1;i<=n;++i)
	{
	dfs(0,a[i],0);
	dfs(0,1,0);
	}
	cout<<ans;
}

