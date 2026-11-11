#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,k;
int a[200005];
bool f[200005];
int sum[200005];
void dfs(int step,int x)
{
	f[x]=1;
	if(step==m+1)
	{
		k=sum[1];
		for(int i=2;i<=step-1;i++)
		{
			k&=sum[i];
		}
		ans=max(ans,k);
		f[x]=0;
		sum[step-1]=0;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			sum[step]=a[i];
			
			dfs(step+1,i);
		}
	}
	f[x]=0;
	sum[step]=0;
	return ;
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
	dfs(1,0);
	cout<<ans;
	
	return 0;
}
