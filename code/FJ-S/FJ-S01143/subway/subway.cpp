#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
const long long inf=1ll<<60;
int id,n,m,d,q;long long w[M],dis[N][N];
vector<pair<int,long long> >V[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&id,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	memset(dis,127/3,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int u;long long v;
			scanf("%d%lld",&u,&v);
			V[u].push_back(make_pair(i,v));
		}
	}
	for(int i=1;i<=m;i++)
	{
		int len=V[i].size(); 
		for(int j=0;j<len;j++)
		  for(int k=j+1;k<len;k++)
			dis[V[i][j].first][V[i][k].first]=dis[V[i][k].first][V[i][j].first]=V[i][j].second+V[i][k].second;
	}
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int len1=V[u].size(),len2=V[v].size();
		long long ans=inf;
		for(int i=0;i<len1;i++)
		  for(int j=0;j<len2;j++)
			ans=min(ans,V[u][i].second+V[v][j].second+dis[V[u][i].first][V[v][j].first]);
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
