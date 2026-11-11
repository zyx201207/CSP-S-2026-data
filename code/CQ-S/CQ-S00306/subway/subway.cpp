#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5 + 5;
struct node
{
	ll v;
	ll w;
};
ll c , n , m , d , q;
ll t[505][505];
ll cost[505][505];//l两条路之间的最小消耗
ll w[505] , m1[505][505];
vector<node> g[505];
void dis(ll x)
{
	queue<pair<ll , pair<ll , ll> > > q;
	for(auto v : g[x])
		q.push({-v.w , {x , v.v}});
	while(!q.empty())
	{
		auto u = q.front();
		q.pop();
		if(t[u.second.second][u.second.first]) continue;
//		cout << u.second.first << " " << u.second.second << " " << -u.first << endl;
		cost[x][u.second.second] = min(cost[x][u.second.second] , cost[x][u.second.first] - u.first);
		t[u.second.second][u.second.first] = 1;
		t[u.second.first][u.second.second] = 1;
		for(auto v : g[u.second.second])
		{
			if(!t[u.second.second][v.v])
			{
				q.push({-v.w , {u.second.second , v.v}});
			}
		}
	}
}
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//初始化 
	for(int i = 1;i <= 500;i++)
	{
		for(int j = 1;j <= 500;j++)
		{
			m1[i][j] = 1e18;
			cost[i][j] = 1e18;
			if(i == j) cost[i][j] = 0;
		}
	}
	
	cin >> c >> n >> m >> d >> q;
	swap(n , m);
	for(int i = 1;i <= n;i++) cin >> w[i];
	for(int i = 1;i <= m;i++)
	{
		int k;
		cin >> k;
		vector<pair<int , ll> > vec; 
		for(int j = 1;j <= k;j++)
		{
			int id;
			ll t;
			cin >> id >> t;
			vec.push_back({id , t});
		}
		for(int j = 0;j < vec.size();j++)
		{
			for(int ij = j + 1;ij < vec.size();ij++)
			{
				ll u = vec[j].first;
				ll v = vec[ij].first;
				ll w1 = vec[j].second + vec[ij].second;
				m1[u][v] = min(m1[u][v] , w1);
				m1[v][u] = min(m1[v][u] , w1);
			}
		}
	}
	//建图 
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(m1[i][j] != 1e18)
			{
				g[i].push_back({j , m1[i][j]});
				g[j].push_back({i , m1[j][i]});
			}
		}
	}
	
	//预处理 
	for(int i = 1;i <= n;i++)
	{
		memset(t , 0 , sizeof(t));
		dis(i);
	}
	for(int i = 1;i <= q;i++)
	{
		ll u , v;
		cin >> u >> v;
		cout << cost[u][v] + w[u] + w[v] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 7 2 3 3 4
3 1 5 2 4 3 7
*/
