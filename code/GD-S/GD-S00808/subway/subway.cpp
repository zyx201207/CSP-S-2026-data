#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10,M=510,inf=1e18;
LL n,m,D,q,w[N];
LL f[M][M];
vector<pair<int,int>> e[N];
inline void chk(LL &x,const LL &y) { x=min(x,y); }
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	LL cid; scanf("%lld",&cid);
	scanf("%lld%lld%lld%lld",&n,&m,&D,&q);
	for(int i=1;i<=m;i++) scanf("%lld",w+i);
	for(int i=1;i<=n;i++)
	{
		LL k,a,t; scanf("%lld",&k);
		while(k--) scanf("%lld%lld",&a,&t),e[a].push_back({t,i});
	}
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=n;j++)
			f[i][j]=(i==j?0:inf);
	for(int u=1;u<=m;u++)
		for(auto i:e[u])
			for(auto j:e[u])
				chk(f[i.second][j.second],i.first+j.first);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chk(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=q;i++)
	{
		LL x,y; scanf("%lld%lld",&x,&y);
		LL ans=inf;
		for(auto i:e[x])
			for(auto j:e[y])
				chk(ans,w[x]+w[y]+i.first+j.first+f[i.second][j.second]);
		printf("%lld\n",ans);
	}
	return 0;
}
