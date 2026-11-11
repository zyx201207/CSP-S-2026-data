#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 2e4;//地铁站 
const int N = 500;//地铁线路 
const int INF = 1e18;

struct S
{
	int to, w;
	bool operator <(const S &other) const
	{
		return other.w < w;
	}
};

vector <S> edge[N + 5];// i号线到j号线 
vector <S> ne[N + 5];// 新的edge  连了首尾上下车 
int w[M + 5];
int t[M + 5][N + 5];
vector <int> v[M + 5]; //每个站台的 线路 
vector <int> id;//可以换乘的地铁站的下标 

vector <int> dis(N + 5, INF);
void solve(int s)
{
	vector <int> vis(N + 5, 0);
	priority_queue <S> q;
	q.push({s, 0});
	dis[s] = 0;
	
	while (!q.empty())
	{
		auto t = q.top();
		q.pop();
		
		int u = t.to;
		if (vis[u] == 1) continue;
		vis[u] = 1;
		
		for (auto p : ne[u])
		{
			int v = p.to, w = p.w;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int len;
		cin >> len;
		for (int j = 1; j <= len; j++)
		{
			int aa, tt;
			cin >> aa >> tt;
			t[i][aa] = tt;
			v[aa].push_back(i);
			if (v[aa].size() >= 2) id.push_back(aa);
		}
	}
	
	for (auto p : id)
	{
		//拿一个换乘站出来
		for (int i = 0; i < v[p].size(); i++)
		{
			for (int j = i + 1; j < v[p].size(); j++)
			{
				int dis = t[i][p] + t[j][p];
				edge[i].push_back({j, dis});
				edge[j].push_back({i, dis});
				//连接线路的边 
			}
		} 
	}
	
	while (q --)
	{
		int x, y;
		cin >> x >> y;
		for (int i = 1; i <= n; i++) ne[i] = edge[i];
		for (int i = 0; i < dis.size(); i++) dis[i] = INF;
		
		for (auto p : v[x]) ne[0].push_back({p, t[p][x]});
		for (auto p : v[y]) ne[p].push_back({501, t[p][y]});
		//连上开始结束的边 
		
		solve(0);
		int ans = dis[501] + w[x] + w[y];
		cout << ans << "\n";
	}
	return 0;
}
