#include<bits/stdc++.h>
using namespace std;
#define int long long
//建图的复杂度炸了，回来再看
//感觉dij也有点炸 

const int N = 500005;
const int M = 505;

int c, n, m, d, qu, a;
int w[N];
int t;
int id[N], idcnt = 0;
int x, y, k[N];
int ans;
int dis[M][M], ln[M][M];
bool vis[M][M];

typedef pair<int, int> PII;
typedef pair<int, int> PI;
vector<PI> st[N];
priority_queue<PII, vector<PII>, greater<PII> >q;

int minx(int xx, int yy)
{
	if(xx < yy)return xx;
	return yy;
}

void dij(int s)
{
	while(!q.empty())q.pop();
	q.push({0, s});
	dis[s][s] = 0;
	int nw;
	while(!q.empty())
	{
		nw = q.top().second;
		q.pop();
		if(vis[s][nw])continue;
		vis[s][nw] = 1;
		for(int i = 1; i <= n; i++)
		{
			int x = ln[nw][i];
			if(dis[s][i] > dis[s][nw] + x)
			{
				dis[s][i] = dis[s][nw] + x;
				q.push({dis[s][i], i});
			}
		}
	}
	return;
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> qu;
	for(int i = 1; i <= m; i++)cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			cin >> a >> t;
			st[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dis[i][j] = 1e18;
			ln[i][j] = 1e18;
		}
	}
	
	int l, r, l2, r2;
	for(int i = 1; i <= m; i++)
	{
		for(auto j : st[i])
		{
			for(auto e : st[i])
			{
				l = j.first;
				r = j.second;
				l2 = e.first;
				r2 = e.second;
				if(l == l2)continue;
				ln[l][l2] = minx(ln[l][l2], r + r2);
			}
		}
	}
	for(int i = 1; i <= n; i++)dij(i);
	
	int minn;
	for(int i = 1; i <= qu; i++)
	{
		cin >> x >> y;
		ans = 0;
		ans += w[x] + w[y];
		minn = 1e18;
		for(auto j : st[x])
		{
			for(auto e : st[y])
			{
				l = j.first;
				r = j.second;
				l2 = e.first;
				r2 = e.second;
				minn = minx(minn, r + r2 + dis[l][l2]);
			}
		}
		ans += minn;
		cout << ans << '\n';
	} 
	
	return 0;
}
