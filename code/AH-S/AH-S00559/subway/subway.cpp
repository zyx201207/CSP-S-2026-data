#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxm=5e5+3,maxn=503;
const LL INF=0x7f7f7f7f7f7f7f7f;
int n,m,q;
LL w[maxm];
vector<pair<int,LL>>v[maxm];
LL dist[maxn][maxn];
LL min(LL a,LL b){return (a<b?a:b);}
void init()
{
	int c,d;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(dist,0x7f,sizeof(dist));
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a;LL t;
			scanf("%d%lld",&a,&t);
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto e:v[i])
		{
			for(auto f:v[i])
			{
				int u=e.first,y=f.first;
				LL d=e.second+f.second;
				dist[u][u]=0;dist[y][y]=0;
				dist[u][y]=min(dist[u][y],d);
				dist[y][u]=min(dist[y][u],d);
			}
		}
	}
}
void Floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			for(int k=1;k<=n;k++)
			{
				if(k==i||k==j) continue;
				if(dist[i][k]==INF||dist[j][k]==INF) continue;
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
				
			}
		}
	}
}
void answer_questions()
{
	for(int i=1;i<=q;i++)
	{
		LL ans=LONG_LONG_MAX;
		int x,y;
		scanf("%d%d",&x,&y);
		for(auto e:v[x])
			for(auto f:v[y])
				ans=min(ans,dist[e.first][f.first]+e.second+f.second);
		printf("%lld\n",ans+w[x]+w[y]);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	Floyd();
	answer_questions();
	return 0;
}
