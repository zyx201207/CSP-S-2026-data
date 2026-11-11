# include <bits/stdc++.h>
# define N 2200
# define pr pair<int , int>
using namespace std;
int c, n, m, d, q, s, e , ans;
int w[N] , dis[N];
int t[N][N];
bool vis[N];
vector<pr>g[500060];
inline void dij()
{
	priority_queue< pr  , vector<pr> , greater<pr> > q;
	dis[s] = 0;
	q.push({t[s][s] , s});
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
//		cout << u << " " << '\n';
		if(u == e) break;
		
		for(auto v:g[u])
		{
			if(dis[v.first] >= dis[u] + t[u][v.first] + t[v.first][v.first])
			{
				dis[v.first] = dis[u] + t[u][v.first] + t[v.first][v.first];
				if(v.first == e) dis[v.first] -= t[e][e];
				q.push({dis[v.first] , v.first});
				
			}
		 } 
	}
}
signed main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
	 cin >> w[i];
	for(int i = 1 , s , k; i <= n; i ++)
	{
		 cin >> k;
		 for(int j = 1; j <= k; j ++)
		 {
		 	cin >> s;
			 cin >> t[i][s];
		 	t[s][i] = t[i][s];
		 	g[i].push_back({s , t[i][s]});
		 	g[s].push_back({i , t[i][s]});
		 }
	}
	
	for(int i = 1; i <= q; i ++)
	{
		cin >> s >> e;
		ans = 0;
		ans += w[s] + w[e];
		memset(dis , 0x3f , sizeof dis);
		memset(vis , 0 , sizeof vis);
		dij();
		ans += dis[e];
		   cout << ans << '\n';
	}
 } 
