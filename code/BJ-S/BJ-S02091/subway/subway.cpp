#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 5e5 + 10, inf = 1e18;
vector<pair<int,int> >hv[N];
int dis[510][510], w[N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q, i, j, k;
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(i=1;i<=m;i++) scanf("%lld", &w[i]);
	for(i=1;i<=n;i++)
	{
		int s, a, t;
		scanf("%lld", &s);
		while(s--) scanf("%lld%lld", &a, &t), hv[a].emplace_back(i,t);
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(i!=j) dis[i][j] = inf;
	for(i=1;i<=m;i++)
	{
		int s = hv[i].size();
		for(j=0;j<s;j++) for(k=j+1;k<s;k++) dis[hv[i][j].fi][hv[i][k].fi] = dis[hv[i][k].fi][hv[i][j].fi] =
			min(dis[hv[i][j].fi][hv[i][k].fi],hv[i][j].se+hv[i][k].se);
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) for(k=1;k<=n;k++) dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
	while(q--)
	{
		int x, y, ans = inf;
		scanf("%lld%lld", &x, &y);
		for(auto i:hv[x]) for(auto j:hv[y]) ans = min(ans,i.se+j.se+dis[i.fi][j.fi]);
		printf("%lld\n", ans+w[x]+w[y]);
	}
	return 0;
}