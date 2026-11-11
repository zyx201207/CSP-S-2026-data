#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int N = 5e2 + 5, M = 5e5 + 5, D = 25;
int c, n, m, d, q, w[M];
int k[N];vector <int> ln[M], tm[M];

ll mp[N][N];
void floyd()
{
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m;i++)scanf("%d", &w[i]);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &k[i]);
		for(int j = 1, x, t;j <= k[i];j++)
			scanf("%d%d", &x, &t), ln[x].push_back(i), tm[x].push_back(t);
	}

	memset(mp, 0x3f, sizeof(mp));
	for(int i = 1;i <= m;i++)
		for(int ui = 0;ui < ln[i].size();ui++)
			for(int vi = 0;vi < ln[i].size();vi++)
			{
				int u = ln[i][ui], v = ln[i][vi];
				if(u == v)continue;
				mp[u][v] = mp[v][u] = min(mp[u][v], (ll)tm[i][ui] + tm[i][vi]);
			}
	for(int i = 1;i <= n;i++)mp[i][i] = 0;
	floyd();

	while(q--)
	{
		int x, y;ll res = INF;
		scanf("%d%d", &x, &y);
		for(int ui = 0;ui < ln[x].size();ui++)
			for(int vi = 0;vi < ln[y].size();vi++)
			{
				int u = ln[x][ui], v = ln[y][vi];
				res = min(res, mp[u][v] + tm[x][ui] + tm[y][vi]);
			}
		res += w[x] + w[y], printf("%lld\n", res);
	}
	return 0;
}
