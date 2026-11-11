#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=502+5,maxm=5e5+5;
const ll inf=1e18+7;
ll f[maxn][maxn];
vector<pair<int,int> >G[maxm];
int n,m,q; int w[maxm];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m>>n>>q>>q;
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=m;i++)
	{
		int k; scanf("%d",&k);
		while(k--)
		{
			int u,val; scanf("%d%d",&u,&val);
			G[u].push_back(make_pair(i,val));
		}
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) f[i][j]=inf;
	for(int i=1;i<=m;i++) f[i][i]=0;
	for(int u=1;u<=n;u++)
	{
		for(auto i:G[u]) for(auto j:G[u])
			f[i.first][j.first]=f[j.first][i.first]=min(f[i.first][j.first],(ll)i.second+j.second);
	}
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=i+1;j<=m;j++)
		f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int u,v; scanf("%d%d",&u,&v);
		ll ans=inf;
		for(auto i:G[u]) for(auto j:G[v])
			ans=min(ans,f[i.first][j.first]+(ll)i.second+j.second);
		ans+=w[u]+w[v];
		printf("%lld\n",ans);
	}
	return 0;
}
