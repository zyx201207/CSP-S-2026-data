#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long int64;
const int LL = 1e6, Mod = 1e9 + 7;
int C, T, N, K, Ans, a[35][35], dis[35][35], c[35];
vector<int>g[LL + 5];
inline int64 read()
{
	int64 k = 0, f = 1;
	char t = getchar();
	while(t < '0' || t > '9')
	{
		if(t == '-')
			f = -1ll;
		t = getchar();
	}
	while(t >= '0' && t <= '9')
	{
		k = k * 10ll + t - '0';
		t = getchar();
	}
	return k * f;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	C = read(), T = read();
	while(T--)
	{
		for(int i = 1; i <= N; i++)
			g[i].clear();
		N = read(), K = read();
		for(int i = 1; i < N; i++)
		{
			int u = read(), v = read();
			g[u].push_back(v), g[v].push_back(u);
		}
		if(C <= 3)
		{
			Ans = 1e9;
			memset(dis, 0x3f, sizeof(dis));
			memset(a, 0, sizeof(a));
			for(int i = 1; i <= N; i++)
				for(int j : g[i])
					a[i][j] = a[j][i] = dis[i][j] = dis[j][i] = 1;
			for(int i = 1; i <= N; i++)
				dis[i][i] = 0;
			for(int k = 1; k <= N; k++)
				for(int i = 1; i <= N; i++)
					for(int j = 1; j <= N; j++)
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			for(int S = 0; S < 1 << N; S++)
			{
				memset(c, 0, sizeof(c));
				int tmp = S, tot = 0, d = 0;
				while(tmp)
				{
					c[++tot] = tmp & 1;
					d += tmp & 1;
					tmp >>= 1;
				}
				if(d == 5)
					tmp = 1;
				if(d != K)
					continue;
				for(int i = 1; i <= tot; i++)
				{
					if(c[i])
					{
						for(int j = i + 1; j <= tot; j++)
						{
							if(c[j] && a[i][j])
								d--;
						}
					}
				}
				if(d > 2)
					continue;
				int t = 0;
				for(int i = 1; i <= N; i++)
				{
					int res = 1e9;
					for(int j = 1; j <= N; j++)
						if(c[j])
							res = min(res, dis[i][j]);
					t = max(t, res);
				}
				Ans = min(Ans, t);
			}
			printf("%d\n", Ans);
		}
		if(C >= 13 && C <= 14)
		{
			int M = (N - 1) / 2;
			if(K == N)
				printf("0\n");
			else if(K >= M)
				printf("1\n");
			else
				printf("%d\n", (M + 1) / 3 - (K + 2) / 4 + 1);
		}
	}
	return 0;
}
