#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool p[200005];
void dfs(int sum,int num)
{
	if(sum>=m)
	{
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0)
		{
			p[i]=1;
			dfs(sum+1,num&a[i]);
			p[i]=0;
		}
	}
}
int main()
{
	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		p[i]=1;
		dfs(1,a[i]);
	}
	cout<<ans;
	return 0;
}
