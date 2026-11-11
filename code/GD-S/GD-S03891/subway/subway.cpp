#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500050];
vector<pair<int,int> > p[550],v[500050];
int s[550][550];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) 
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;++i)
	{
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;++j)  
		{
			int x,y;
			scanf("%lld%lld",&x,&y);
			p[i].push_back({x,y});
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i!=j) s[i][j]=1e18+10;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<p[i].size();++j)
		{
			int x=p[i][j].first,y=p[i][j].second;
			for(int k=0;k<v[x].size();++k)
			{
				int z=v[x][k].first;
				s[i][z]=min(s[i][z],y+v[x][k].second);
			}
		}
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			if(s[i][k]==1e18+10) continue;
			for(int j=1;j<=n;++j)
			{
				if(s[i][k]+s[k][j]<s[i][j]) s[i][j]=s[i][k]+s[k][j];
			}
		}
	}
	while(q--)
	{
		int x,y,ans=1e18;
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<v[x].size();++i)
		{
			int u=v[x][i].first,o=v[x][i].second;
			for(int j=0;j<v[y].size();++j)
			{
				int z=v[y][j].first,r=v[y][j].second;
				if(s[u][z]+w[x]+w[y]+o+r<=ans) ans=s[u][z]+w[x]+w[y]+o+r;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
