#include <bits/stdc++.h>
using namespace std;

#define int long long

char st;

const int N = 505, M = 5e5 + 10, inf = 1e18, Q = 1e5 + 10;
int c, n, m, D, q;
int w[M];
//vector <pair <int, int> > a[N];
int head[M+N], to[2*(M+N)], nxt[2*(M+N)], val[2*(M+N)], cn;
void add(int x, int y, int w)
{
    to[++cn] = y, val[cn] = w;
    nxt[cn] = head[x];
    head[x] = cn;
}

int dis[M+N];
int32_t b[N][M];
int d[N][N];

bool vis[N];
struct Query
{
	int s, t;
} que[Q];
int ans[Q];

priority_queue <pair <int, int> > qu;

char ed;

void work(int s)
{
    for (int i = 1; i <= n; ++i)
        dis[i + m] = inf;
    
    dis[s] = 0;
    qu.push({0, s});
    while (!qu.empty())
    {
        int s = qu.top().first, x = qu.top().second;
        qu.pop();
        for (int i = m + 1; i <= m + n; ++i)
        {
        	if (i == x)
        		continue ;
        	if (dis[i] > dis[x] + d[x-m][i-m])
        	{
        		dis[i] = dis[x] + d[x-m][i-m];
        		qu.push({dis[i], i});
			}
		}
    }
    for (int i = 1; i <= q; ++i)
    {
    	if (b[s-m][que[i].s])
    	{
    		for (int j = head[que[i].t]; j; j = nxt[j])
    		{
    			int go = to[j], w = val[j];
    			ans[i] = min(ans[i], dis[go] + w + b[s-m][que[i].s]);
			}
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0), cout.tie(0);
    cin >> c >> n >> m >> D >> q;
    for (int i = 1; i <= m; ++i)
        cin >> w[i];
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j)
        {
            int x, y;
            cin >> x >> y;
            // a[i].push_back({x, y});
            add(x, i + m, y);
            add(i + m, x, y);
            b[i][x] = y;
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
    	for (int j = 1; j <= n; ++j)
    	{
    		d[i][j] = inf;
		}
	}
    
    for (int i = 1; i <= m; ++i)
    {
    	for (int j = head[i]; j; j = nxt[j])
    	{
    		int x = to[j], v = val[j];
    		for (int k = head[i]; k; k = nxt[k])
    		{
    			if (j == k)
    				continue ;
    			int y = to[k], w = val[k];
    			d[x-m][y-m] = min(d[x-m][y-m], v + w);
			}
		}
	}
    
//    for (int i = 1; i <= n; ++i)
//    {
//    	for (int j = 1; j <= n; ++j)
//    	{
//    		cerr << d[i][j] << ' ';
//		}
//		cerr << '\n';
//	}
    
    for (int i = 1; i <= q; ++i)
    	cin >> que[i].s >> que[i].t, ans[i] = inf;

    for (int i = 1; i <= n; ++i)
    	work(i + m);
    
    for (int i = 1; i <= q; ++i)
    	cout << ans[i] + w[que[i].s] + w[que[i].t] << '\n';
    	
//	cerr << abs(&st - &ed) * 1.0 / 1024 / 1024 << '\n';
    return 0;
}
