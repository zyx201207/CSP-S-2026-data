#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans;
void dfs(long long cnt,long long sum,long long step)
{
	if(step==m)
	{
		ans=max(ans,sum);
		return ;
	}
	if(step+n-cnt<m)
	{
		return ;
	}
	for(int i=cnt+1;i<=n;i++)
	{
		dfs(i,sum&a[i],step+1);
	}
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
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(n-i+1<m)
		{
			break;
		}
		dfs(i,a[i],1);
	}
	cout<<ans;
	return 0;
}

