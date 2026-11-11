#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define inf (int)(4e18)
using namespace std;

const int N = 5e3 + 5;
int c,t,x[N],n,d,dis[N][N],cnt[N][N];
vector<int> e[N];

void init()
{
	for(int i = 1;i <= n;i++) e[i].clear();
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) dis[i][j] = inf,cnt[i][j] = 0;
}

void dijkstra(int rt)
{
	dis[rt][rt] = 0,cnt[rt][rt] = 1;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	vector<int> vis(n + 5,0);
	q.push({dis[rt][rt],rt});
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int& v : e[u])
		{
			if(dis[rt][v] > dis[rt][u] + 1)
			{
				dis[rt][v] = dis[rt][u] + 1,cnt[rt][v] = cnt[rt][u];
				q.push({dis[rt][v],v});
			}
			else if(dis[rt][v] == dis[rt][u] + 1) cnt[rt][v] += cnt[rt][u];
		}
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		init(); 
		for(int i = 1;i <= n;i++) cin >> x[i];
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if(x[j] - x[i] > d) break;
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
		for(int i = 1;i <= n;i++) dijkstra(i);
		int ans = 0;
		
		for(int u = 1;u <= n;u++)
			for(int v = u;v <= n;v++)
				ans += (cnt[u][v] == 2);
		cout << ans << "\n";
	}
	return 0;
} 
