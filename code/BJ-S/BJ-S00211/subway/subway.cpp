#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pii;

const int N = 505 , M = 5e5 + 5;

ll d[N][N];
int c , n , m , lim , q , len , a , tim;
int waste[M];
vector<pii> G[M] , g[N];

ll dist[N];
bool st[N];

void dijkstra(int s)
{
	for(int i = 0 ; i <= n ; ++ i) dist[i] = 1e18 , st[i] = 0;
	dist[s] = 0;
	priority_queue< pii , vector<pii> , greater<pii> > pq;
	pq.push({0 , s});
	
	while(pq.size())
	{
		auto x = pq.top();
		pq.pop();
		ll id = x.second , dis = x.first;
		if(st[id]) continue;
		st[id] = 1;
		for(auto t : g[id])
		{
			if(dist[t.second] > dis + t.first)
			{
				dist[t.second] = dis + t.first;
				pq.push({dist[t.second] , t.second});
			}
		}
	}
	for(int i = 1 ; i <= n ; ++ i) d[s][i] = d[i][s] = min(d[s][i] , dist[i]);
	
	return ;
}

int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> c >> n >> m >> lim >> q;
	for(int i = 1 ; i <= n ; ++ i)
		for(int j = 1 ; j <= n ; ++ j)
			d[i][j] = 1e18;
	for(int i = 1 ; i <= n ; ++ i) d[i][i] = 0;
	for(int i = 1 ; i <= m ; ++ i) cin >> waste[i];
	for(int i = 1 ; i <= n ; ++ i)
	{
		cin >> len;
		while(len --)
		{
			cin >> a >> tim;
			G[a].emplace_back(tim , i);
		}
	}
	for(int i = 1 ; i <= m ; ++ i)
	{
		int sz = G[i].size();
		for(int j = 0 ; j < sz - 1 ; ++ j)
			for(int k = j + 1 ; k < sz ; ++ k)
				d[G[i][j].second][G[i][k].second] = d[G[i][k].second][G[i][j].second] = min(d[G[i][j].second][G[i][k].second] , (ll)G[i][j].first + G[i][k].first);
	}
	
	for(int i = 1 ; i < n ; ++ i)
		for(int j = i + 1 ; j <= n ; ++ j)
				{g[i].emplace_back(d[i][j] , j); g[j].emplace_back(d[i][j] , i);}
	
	for(int i = 1 ; i <= n ; ++ i) dijkstra(i);
	
	
	while(q --)
	{
		int s , t;
		cin >> s >> t;
		ll res = waste[s] + waste[t] , mini = 1e18;
		
		for(auto x1 : G[s])
			for(auto x2 : G[t])
				mini = min(mini , (ll)x1.first + x2.first + d[x1.second][x2.second]);
		res += mini;
		cout << res << '\n';
	}
	
	return 0;
}
