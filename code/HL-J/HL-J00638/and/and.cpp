#include<bits/stdc++.h>
using namespace std;
long long vis[1000000]={},m,n,ans=0,maxx=-1;
void dfs(long long x,long long zhi)
{
	if(x==m)
	{
		ans=max(zhi,ans);
		return;
	}
	for(int i=1;i<=maxx;i++)
	{
		if(vis[i])
		{
			vis[i]--;
			dfs(x+1,zhi&i);
			vis[i]++;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<long long>a(1000001);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[a[i]]++;
		maxx=max(maxx,a[i]);
	}
	dfs(0,(1<<35)-1);
	cout<<ans;
	return 0;
}
