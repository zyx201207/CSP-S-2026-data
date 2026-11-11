#include <bits/stdc++.h>
using namespace std;

set < set < int > > ha;

set < int > choise(int k, vector < vector < int > > adj, int u)
{
	set < int > ret;
	ret.push(u);
	while (ret.size() < k)
	{
		for (int i : ret)
		{
			int r = rand() % adj[i].size();
			if (ret.count(adj[i][r]) == 0)
				ret.push(r);
			if (ret.size() == k ) 
				if (ha.count(ret) == 0)return ret; else {
				ret.clear(); ret.push(u);
			}
		}
	}
	return ret;
}

int bfs(int st, int en, vector < vector < int > > adj)
{
	queue < pair < int , int > > q;
	q.push({st, 0});
	while (!q.empty())
	{
		int u = q.front().first, l = q.front().second;
		
	}
	return 
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	srand(time(0));
	
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector < vector < int > > adj(n, vector < int > (n));
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		if (n <= k)
		{
			cout << 0 << endl;
			continue;
		}
		
		set < int > s = choise();
		
		for (int i = 0; i < n; i++)
		{
			if (s.count(i) == 1) continue;
			else 
			{
				
			}
		}
	}
	return 0;
}
