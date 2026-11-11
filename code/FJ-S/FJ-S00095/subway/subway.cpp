#include <vector>
#include <cstring>
#include <iostream>

#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

typedef pair <int, int> PII;

const int N = 510, M = 500010;

int cost[N];
int dist[N][N];
int n, m, q, d, c;
vector <PII> lines[N];
vector <PII> belongs[M];

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	
	return x * f;
}

inline void write(int x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

signed main()
{
	memset(dist, 0x3f, sizeof dist);	
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
//	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++ i )
	{
		cost[i] = read();
//		scanf("%lld", &cost[i]);
	}
	for (int i = 1; i <= n; ++ i )
	{
		int cnt = read();
//		scanf("%lld", &cnt);
		 
		while (cnt -- )
		{
			PII tmp = { 0, 0 };
			tmp.first = read(), tmp.second = read();
//			scanf("%lld%lld", &tmp.first, &tmp.second);
			lines[i].push_back(tmp);
//			cost[tmp.first] += tmp.second;
			
			int idx = tmp.first;
			
			tmp.first = i;
			belongs[idx].push_back(tmp);
		}
	}
	
	for (int i = 1; i <= m; ++ i )
	{
		for (int j = 0; j < belongs[i].size(); ++ j )
			for (int k = 0; k < j; ++ k )
			{
				dist[belongs[i][j].first][belongs[i][k].first]
					= min(dist[belongs[i][j].first][belongs[i][k].first],
					belongs[i][j].second * 1LL + belongs[i][k].second);
				dist[belongs[i][k].first][belongs[i][j].first]
					= dist[belongs[i][j].first][belongs[i][k].first];
			}
	}
	
	for (int i = 1; i <= n; ++ i )
		dist[i][i] = 0; 
	
	for (int k = 1; k <= n; ++ k )
		for (int i = 1; i <= n; ++ i )
		{
//			if (dist[i][k] == INF) continue;
			for (int j = 1; j <= n; ++ j )
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	
	while (q -- )
	{
		int S = read(), T = read();
//		int S = 0, T = 0;
//		scanf("%lld%lld", &S, &T);
		
		int res = INF;
		for (int i = 0; i < belongs[S].size(); ++ i )
			for (int j = 0; j < belongs[T].size(); ++ j )
			{
				res = min(res, dist[belongs[S][i].first][belongs[T][j].first] + belongs[S][i].second + belongs[T][j].second);
			}
		res += cost[S] + cost[T];
		
//		printf("%lld\n", res); 
		write(res), putchar('\n');
	}
//	
//	puts("");
//	for (int i = 1; i <= m; ++ i )
//	{
//		printf("%lld:\n", i);
//		for (int j = 0; j < belongs[i].size(); ++ j )
//		{
//			printf("%lld %lld\n", belongs[i][j].first, belongs[i][j].second);
//			if (j == belongs[i].size() - 1) puts("");
//		}
//	}
	
	return 0;
}
