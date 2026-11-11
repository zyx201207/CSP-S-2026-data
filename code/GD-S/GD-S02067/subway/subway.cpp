#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
//#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int c, n, m, d, q;
struct node{
//	int lens;
	int lie[505];
	int num[505];
} sta[N];
struct node1{
	int lie;
	int sta;
};
struct node2{
	int lie;
	long long sum;
};
int cost[N];
int a[505][N], t[505][N];
int k[505];
int s, e;
long long ans;
vector<node1> g[N];
int o[505][N];
long long vis[505];
void bfs(int lie, long long sum)
{
	if(o[lie][e])
	{
		sum += t[lie][sta[e].num[lie]];
		ans = min(ans, sum);
		return ;
	}
	queue<node2> q;
	q.push({lie, sum});
	while(!q.empty())
	{
		node2 tp = q.front();
		q.pop();
		int l = tp.lie;
		long long sm = tp.sum;
		if(o[l][e])
		{
			sm += t[l][sta[e].num[l]];
			ans = min(ans, sm);
			continue;
		}
		if(sm > ans) continue;
//		cout << l << " " << sm << endl;
		for(int i = 0;i < g[l].size(); i ++)
		{
			int v = g[l][i].lie, st = g[l][i].sta;
			if(v == l) continue;
//			cout << v << " " << st << endl;
			int cnt = t[l][sta[st].num[l]] + t[v][sta[st].num[v]];
//			cout << cnt << endl;
			if(!vis[v] || vis[v] > cnt + sm)
			{
				vis[v] = cnt + sm;
				q.push({v, vis[v]});
			}
		}
	}
	
}
void init()
{
	ans = INF;
	memset(vis, 0, sizeof(vis));
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	cin >> c >> n >> m >> d >> q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m;i ++) cin >> cost[i];
	for(int i = 1;i <= n;i ++)
	{
//		cin >> k[i];
		scanf("%d", &k[i]);
		for(int j = 1;j <= k[i];j ++)
		{
//			cin >> a[i][j] >> t[i][j];
			scanf("%d%d", &a[i][j], &t[i][j]);
			o[i][a[i][j]] ++;
			sta[a[i][j]].lie[i] = 1;
			sta[a[i][j]].num[i] = j;
		}
	}
	
	for(int i = 1;i <= m;i ++)
	{
		for(int j = 1;j < n;j ++)
		{
			if(!sta[i].lie[j]) continue;
			for(int k = j + 1;k <= n;k ++)
			{
				if(!sta[i].lie[k]) continue;
				g[j].push_back({k, i});
				g[k].push_back({j, i});
			}
		}
	}
	
	while(q--)
	{
		cin >> s >> e;
		init();
		int ini = cost[s] + cost[e];
		for(int i = 1;i <= n;i ++)
		{
			if(!sta[s].lie[i]) continue;
//			cout << i << endl;
			int x = t[i][sta[s].num[i]];
			bfs(i, x + ini);
		}
		cout << ans << endl;
	}
	return 0;
}

