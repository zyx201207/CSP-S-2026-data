#include <iostream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

using uint = unsigned int;
using u64 = unsigned long long;

struct Edge
{
	int to, v;
};

vector<Edge> p[1000501];
//0 Station Hall
//1 Exit

struct BFS
{
	int id;
	u64 v;
	
	bool operator<(BFS x) const {return this->v < x.v;}
	bool operator>(BFS x) const {return this->v > x.v;}
};

u64 bfs(int fm, int to)
{
	static bitset<1000501> f;
	priority_queue<BFS, vector<BFS>, greater<BFS> > q;
	
	f.reset();
	q.push({fm, 0});
	while (!q.empty())
	{
		BFS x = q.top();
		q.pop();
		
		if (x.id == to) return x.v;
		
		if (f[x.id]) continue;
		f[x.id] = 1;
		
		for (uint i = 0; i < p[x.id].size(); ++i)
		{
			q.push({p[x.id][i].to, x.v + p[x.id][i].v});
		}
	}
	
	return ~(u64)0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
	{
		int w;
		cin >> w;
		
		p[(i << 1)].push_back({(i << 1 | 1), w});
		p[(i << 1 | 1)].push_back({(i << 1), w});
	}
	for (int i = 1; i <= n; ++i)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j)
		{
			int a, t;
			cin >> a >> t;
			
			p[(a << 1)].push_back({i + 1000000, t});
			p[i + 1000000].push_back({(a << 1), t});
		}
	}
	
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		x = x << 1 | 1;
		y = y << 1 | 1;
		
		cout << bfs(x, y) << '\n';
	}
	
	return 0;
}
