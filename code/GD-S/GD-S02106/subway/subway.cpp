#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;
int n,m,_d,q,w[M];
vector<pair<int,int> > g[M+N];
long long dis[N][N];


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%*d %d %d %d %d",&n,&m,&_d,&q);
	for(int i=1;i<=m;i++)scanf("%d",w+i);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1,k,a,t;i<=n;i++)
	{
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d %d",&a,&t);
			g[i].emplace_back(n+a,t);
			g[n+a].emplace_back(i,t);
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(const auto p:g[n+i])
		{
			for(const auto q:g[n+i])
			{
				if(q.first==p.first)break;
				dis[p.first][q.first]=min(dis[p.first][q.first],(long long)(p.second+q.second));
				dis[q.first][p.first]=min(dis[q.first][p.first],(long long)(p.second+q.second));
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		long long ans=0x3f3f3f3f3f3f3f3fll;
		for(const auto p:g[n+x])
		{
			for(const auto q:g[n+y])
			{
				ans=min(ans,p.second+q.second+dis[p.first][q.first]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
