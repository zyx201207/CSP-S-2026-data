#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+7,N=507;
int c,m,n,d,q,w[M],dis[N][N];
vector<pair<int,int>> G[N],g[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	int i,j,k,to,v,x,y,ans;
	for(i=1;i<=m;i++) cin >> w[i];
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) dis[i][j]=LLONG_MAX/4;
	for(i=1;i<=n;i++) dis[i][i]=0;
	for(i=1;i<=n;i++)
	{
		cin >> k;
		for(j=1;j<=k;j++)
		{
			cin >> to >> v;
			G[i].push_back({to,v});
			g[to].push_back({i,v});
		}
	}
	for(i=1;i<=m;i++)
	{
		for(auto it1:g[i])
		{
			for(auto it2:g[i])
			{
				if(it1==it2) continue;
				dis[it1.first][it2.first]=it1.second+it2.second;
			}
		}
	}
	for(k=1;k<=n;k++) for(i=1;i<=n;i++) for(j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		cin >> x >> y; ans=LLONG_MAX;
		for(auto it1:g[x]) for(auto it2:g[y]) ans=min(ans,it1.second+it2.second+dis[it1.first][it2.first]);
		cout << ans+w[x]+w[y] << '\n';
	}
	return 0;
}
