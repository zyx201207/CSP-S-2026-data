#include <iostream>
#include <cstdio>
using namespace std;
long long c,t,n,d,a[2000010];
long long tong[2000010];
void dfs(int now,int to,int dis)
{
	if (now==to)
	{
		tong[dis]++;
		return;
	}
	for (int i=now+1;i<=n;i++)
	{
		if (a[i]-a[now]>d)break;
		dfs(i,to,dis+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		long long ans=0;
		for (int i=1;i<=n;i++)cin>>a[i];
		for (int u=1;u<n;u++)
		{
			int v=u+1;
			while(a[v]-a[u]<=d)v++;
			for (;v<=n;v++)
			{
				for (int i=1;i<=n;i++)tong[i]=0;
				dfs(u,v,0);
				for (int k=1;k<=n;k++)if (tong[k]){ans+=(int)(tong[k]==2);break;}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

