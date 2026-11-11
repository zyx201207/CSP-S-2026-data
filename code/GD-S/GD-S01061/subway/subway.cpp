#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 505, INF = 0x3f3f3f3f, M = 5e5 + 5;
int c, n, m, d, q;

struct Code{
	int v, w;
	bool operator < (const Code& other)const
	{
		return w > other.w;
	}
};
priority_queue<Code> Q;
vector<Code> in[M], out[M];
int k[N], w[M];
long long dist[N];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++)
		{
			int a, t;
			cin >> a >> t; 
			in[a].push_back({i, t});//表示从a[i][j]地铁站站台可以花t[i][j]时间进入i线 
			out[i].push_back({a,t});//表示从i线可以花t[i][j]的时间进入a[i][j]地铁站站台 
		}
	}
	while(q --)
	{
		int x, y;
		cin >> x >> y;
		
		fill(dist, dist + m + 1, INF);
		Q.push({x, w[x]}); 
		dist[x] = w[x];
		while(!Q.empty())
		{
			Code t = Q.top();
			Q.pop();//到达v号地铁站厅, 步行时间为w 
			if(t.w > dist[t.v])
			{
				continue;
			}
			for(int i = 0;i < in[t.v].size();i ++)
			{
				int p = in[t.v][i].v;
				for(int l = 0;l < out[p].size();l ++)
				{
					int v = out[p][l].v;
					int w = t.w + in[t.v][i].w + out[p][l].w;
					if(dist[v] > w)
					{
						dist[v] = w;
						Q.push({v, w});
					}
				}
			}
		}
		cout << dist[y] + w[y] << '\n';
		while(!Q.empty())
		{
			Q.pop();
		}
	} 
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
