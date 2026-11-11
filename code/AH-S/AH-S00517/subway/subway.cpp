#include<bits/stdc++.h>
using namespace std;
int C,n,m,D,q,w[500010];
vector<pair<int,int>> e[500010];
long long f[510][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof f);
	int k,a,t,u,v;
	long long ans;
	scanf("%d%d%d%d%d",&C,&n,&m,&D,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",w+i);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		f[i][i]=0;
		while(k--)
		{
			scanf("%d%d",&a,&t);
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		int len=e[i].size();
		for(int j=0;j<len;j++)
			for(int k=j+1;k<len;k++)
				f[e[i][j].first][e[i][k].first]=f[e[i][k].first][e[i][j].first]=min(f[e[i][k].first][e[i][j].first],1LL*e[i][j].second+e[i][k].second);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		scanf("%d%d",&u,&v),ans=0x3f3f3f3f3f3f3f3f;
		for(auto uu:e[u])for(auto vv:e[v])
			ans=min(ans,uu.second+vv.second+f[uu.first][vv.first]);
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
//14:59 completed
//15:06 debug&tested
