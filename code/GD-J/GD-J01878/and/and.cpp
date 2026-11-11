#include <bits/stdc++.h>
using namespace std;
long long n,m,k[20005],cnt;
int u[20005];
int dfs(int d,int cs)
{
	if (cs==n+1)
	{
		if (d==m)
		{
			long long ans=u[1];
			for (int i = 1;i<=n;i++)
			{
				if (u[i]==1)
				{
					ans=(ans&&k[i]);
				}
			}
			cnt=max(ans,cnt);
		}
	}
	u[cs]=1;
	dfs(d+1,cs+1);
	u[cs]=0;
	dfs(d,cs+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n;i++)
	{
		cin>>k[i];
	}
	dfs(0,1);
	cout<<cnt;
}
