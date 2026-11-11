#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000010];
vector<int> g[310];
int dis[310][310] , cnt[310][310];

inline void bfs(int s)
{
	queue<int> q;
	q.push(s);
	dis[s][s] = 0;
	cnt[s][s] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
//		cout << u << " ";
		for(int v : g[u])
		{
			if(dis[s][v] > dis[s][u] + 1)
			{
				dis[s][v] = dis[s][u] + 1;
				cnt[s][v] = cnt[s][u];
				q.push(v);
			}
			else if(dis[s][v] == dis[s][u] + 1)
			{
				cnt[s][v] += cnt[s][u];
			}
		}
	}
}

inline void work()
{
	memset(dis , 0x3f , sizeof dis);
	memset(cnt , 0 , sizeof cnt);
	int n , d;
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i++)cin >> x[i];
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			if(abs(x[i] - x[j]) <= d)g[i].push_back(j);
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		bfs(i);
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = i + 1 ; j <= n ; j++)
		{
			if(cnt[i][j] == 2)ans++;
		}
	}
	cout << ans << endl;
	for(int i = 1 ; i <= n ; i++)g[i].clear();
}
signed main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , t;
	cin >> c >> t;
	while(t--)
	{
		work();
	}
	return 0;
}
