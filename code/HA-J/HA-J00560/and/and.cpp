#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,m,ans=INT_MIN;
bool b[200010]={0};
void dfs(int k,long long v)
{
	if(k>m)
	{
		ans=max(ans,v);return ;
	}
	for(int i=k+1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			dfs(k+1,v&a[i]);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(n==m)
	{
		ans=0;for(int i=1;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=1;
		dfs(2,a[i]);
		b[i]=0;
	}
	cout<<ans;
	return 0;
}
