#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[200010];
long long b[200010];
long long mi=1e14;
long long ans=0;
void dfs(long long u,long long v,long long cnt)
{
	if(u==v)
	{
		if(cnt<mi)
		{
			mi=cnt;
			ans=1;
		}
		if(cnt==mi)ans++;
	}
	for(long long i=u;i<=min(u+b[u],v);i++)
	{
		dfs(i,v,cnt+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);         //¼ÇµÃÉ¾×¢ÊÍ 
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			int j=0;
			while(i+j<=n)
			{
				if(a[j+1]>a[i]+d)break;
				j++;
			}
			b[i]=j;
		}
		int ans2=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				dfs(i,j,0);
				ans=0;
				mi=1e14;
				if(ans==2)ans2++;
			}
		}
		cout<<ans2<<endl;
	}
	return 0;
}
