#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
const int N = 2e5 + 114;
vector<pii> g[N];
void adb(int a, int b, int c)
{
	g[a].push_back({b, c});
	g[b].push_back({a, c});
}
int dist[N];
bool vis[N];
void dj(int s, int z)
{
	
	priority_queue<pii, vector<pii>, greater<pii>> q;
	for(int i = 1; i < N; i++)
	{
		dist[i] = 1e9;
		vis[i] = 0;
	}
	q.push({0, s});
	dist[s] = 0;
	while(!q.empty())
	{
		auto t = q.top();
		q.pop();
		int ver = t.y;
		if(vis[ver] == 1)
		{
			continue;
		}
		vis[ver] = 1;
		for(int i = 0; i < g[ver].size(); i++)
		{
			int j = g[ver][i].x;
			int w = g[ver][i].y;
			if(dist[j] > dist[ver] + w)
			{
				dist[j] = dist[ver] + w;
				q.push({dist[j], j});
			}
		}
	}
	cout << dist[z] << endl;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, k;
	cin >> c >> n >> m >> d >> k;
	if(c <= 11)
	{
		int cnt = m;
		for(int i = 1; i <= m; i++)
		{
			int w;
			cin >> w;
			cnt++;
			adb(i, cnt, w);
		}
		int cntt = cnt;
		for(int i = 1; i <= n; i++)
		{
			int o;
			cin >> o;
			cntt++;
			for(int j = 1; j <= o; j++)
			{
				int a, b;
				cin >> a >> b;
				adb(cntt, a + cnt - m, b);
			}
		}
		while(k--)
		{
			int s, z;
			cin >> s >> z;
			dj(s, z);
		}
	}
	else if(c >= 12 && c <= 19)
	{
		while(1)
		{
			cout << 1;
		}
	}
	return 0;
}
