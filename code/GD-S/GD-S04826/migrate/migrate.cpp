#include<bits/stdc++.h>
using namespace std;
long long c,t;
const int MAXN=2e6+1000;
long long n,d;
long long a[MAXN];
long long ans=0;
long long dfs(int u,int v)
{
	if(u==v)
	{
		return 1;
	}
	long long res=0;
	for(int i=u+1;i<=v;i++)
	{
		if(a[i]-a[u]<=d)
		{
			res+=dfs(i,v);
		}
	}
	return res;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int u=1;u<=n;u++)
		{
			for(int v=u+1;v<=n;v++)
			{
				if(dfs(u,v)==2)
				{
					ans++;
				}
			}
		}
		memset(a,0,sizeof a);
		cout<<ans-1<<'\n';
		ans=0;
	}
	return 0;
}
