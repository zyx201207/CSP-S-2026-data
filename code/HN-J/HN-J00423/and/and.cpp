#include<bits/stdc++.h>
using namespace std;
int a[200010],v[200010];
int n,m,ans=0;
int dfs(int lin,int shu,int k)
{
	if(lin==0)
	{
		ans=max(ans,shu);
		return 0;
	}
	for(int i=k+1;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			dfs(lin-1,shu&a[i],i);
			v[i]=0;
		}
	}
	return 0;
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
		v[i]=1;
		dfs(m-1,a[i],i);
		v[i]=0;
	}
	cout<<ans;
	return 0;
}
