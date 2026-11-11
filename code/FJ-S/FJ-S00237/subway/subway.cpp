#include <iostream>
#include <vector>

using namespace std;

template <typename T>
inline void read(T &Fw)
{
	static char Fc;
	Fw = 0;
	do {Fc = getchar();}while ((Fc < '0' || Fc > '9'));
	do {Fw = (Fw << 1) + (Fw << 3) + (Fc ^ 48), Fc = getchar();}while (Fc >= '0' && Fc <= '9');
}

const int N = 510, M = 500010;
const long long INF = 0x7f7f7f7f7f7f7f7f;

int C, n, m, D, Q, w[M];
long long f[N][N];
vector<pair<int, int> > G[M];
int len[M];

void solve()
{
	read(C), read(n), read(m), read(D), read(Q);
	for (int i = 1; i <= m; ++ i) read(w[i]);
	for (int i = 1; i <= n; ++ i)
	{
		for (int j = 1; j <= n; ++ j)
		{
			f[i][j] = INF;
		}
		f[i][i] = 0;
	}
	for (int u = 1, cnt, id, t; u <= n; ++ u)
	{
		read(cnt);
		for (int i = 1; i <= cnt; ++i)
		{
			read(id), read(t);
			for (int j = 0; j < len[id]; ++ j)
			{
				f[G[id][j].first][u] = f[u][G[id][j].first] = min(f[u][G[id][j].first], 1ll * t + G[id][j].second);
			}
			G[id].emplace_back(make_pair(u, t)), ++ len[id];
		}
	}
	for (int k = 1; k <= n; ++ k)
	{
		for (int i = 1; i <= n; ++ i)
		{
			if (f[i][k] == INF) continue;
			for (int j = 1; j <= n; ++ j)
			{
				if (f[k][j] == INF) continue;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	
	int a, b;
	long long ans;
	while (Q -- )
	{
		read(a), read(b), ans = INF;
		for (int i = 0; i < len[a]; ++ i)
		{
			for (int j = 0; j < len[b]; ++ j)
			{
				ans = min(ans, f[G[a][i].first][G[b][j].first] + G[a][i].second + G[b][j].second);
//				cout << G[a][i].first <<" " << G[b][j].first << endl;
			}
		}
//		if (ans == INF) puts("HAHA");
		printf("%lld\n", ans + w[a] + w[b]);
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	solve();
	
	return 0;
}
