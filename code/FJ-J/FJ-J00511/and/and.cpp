#include<bits/stdc++.h> 
using namespace std;
int n,m,a[200005],v[200005],ans;
void dfs (int s,int cnt)
{
	cnt++;
	v[cnt]=a[s];
	if(cnt==m)
	{
		int sum=v[1];
		for(int i=2;i<=cnt;i++)
		{
			sum &= v[i];		
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=s+1;i<=n-m+cnt+1;i++)
	{
		
		dfs(i,cnt);
	}
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
	for(int i=1;i<=n-m+1;i++)
	{
		
		dfs(i,0);
	}
	cout<<ans;
	return 0;
}
