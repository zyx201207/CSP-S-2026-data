#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const long long INF = -1e18;
long long c , n , m , d , q , k , a , t;
vector <long long> w;
vector < vector < pair<long long , long long> > > g(N);
inline long long dijkstra(long long xr , long long yr , long long n) 
{
	long long dis[n + 5] , vis[n + 5];
	fill(dis , dis + n + 1 , INF);
	memset(vis , false , sizeof(vis));
	priority_queue <long long> q;
	q.push(xr)
}
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++)
	{
		int o;
		cin >> o;
		w.push_back(o);
	}
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> k;
		for(int j = 1 ; j <= k ; j++)
		{
			cin >> a >> t;
			long long a1 = a;
			if(j == 1)
			{
				g[0].push_back({a , t});
			}
			else
			{
				g[a1].push_back({a , t});
				g[a].push_back({a1 , t});
			}
		}
	}
	while(q--)
	{
		long long xr , yr , ans = 0;
		cin >> xr >> yr;
		ans += w[xr - 1] + w[yr - 1];
		ans += dijkstra(xr , yr , n);
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
