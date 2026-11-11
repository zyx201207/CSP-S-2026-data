#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ma=-0x3f3f3f3f,vis[200010],k;
void dfs(long long x,long long sum)
{
	if(x==m+1)
	{
		ma=max(ma,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(x==1)
		{
			dfs(x+1,a[i]);
		}
		if(vis[i]!=1)
		{
			vis[i]=1;
			dfs(x+1,sum&a[i]);
			
		}
	}
}
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vis[1]=1;
	dfs(1,0);
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


