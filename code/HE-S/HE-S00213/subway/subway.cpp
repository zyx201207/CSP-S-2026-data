#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5,M = 505;
struct node
{
	int id,w,cnt;
	pair <int,int> t[25];
}a[N];
int _,n,m,d,q,e[M][M],dis[M][M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> _ >> m >> n >> d >> q;
	for(int i = 1;i <= n;i ++) cin >> a[i].w,a[i].id = i;
	for(int i = 1;i <= m;i ++)
	{
		int ki;cin >> ki;
		for(int j = 1;j <= ki;j ++)
		{
			int a1,t1;cin >> a1 >> t1;
			a[a1].t[++ a[a1].cnt].first = i;
			a[a1].t[a[a1].cnt].second = t1;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= m;i ++) dis[i][i] = 0;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j < a[i].cnt;j ++)
		{
			for(int k = j + 1;k <= a[i].cnt;k ++)
			{
				pair <int,int> u_ = a[i].t[j],v_ = a[i].t[k];
				int u = u_.first,v = v_.first,w = u_.second + v_.second;
				dis[u][v] = min(dis[u][v],w);
				dis[v][u] = min(dis[v][u],w);
			}
		}
	}
	for(int k = 1;k <= m;k ++)
		for(int i = 1;i <= m;i ++)
			for(int j = i + 1;j <= m;j ++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]),
				dis[j][i] = min(dis[j][i],dis[i][k] + dis[k][j]);
	
	while(q --)
	{
		int u,v;cin >> u >> v;
		if(u > v) swap(u,v);
		int ans = LLONG_MAX;
		for(int i = 1;i <= a[u].cnt;i ++)
			for(int j = 1;j <= a[v].cnt;j ++)
			{
				pair <int,int> U = a[u].t[i],V = a[v].t[j];
				ans = min(ans,a[u].w + a[v].w + U.second + V.second + dis[U.first][V.first]);
			}	
		cout << ans << endl;
	}
}
