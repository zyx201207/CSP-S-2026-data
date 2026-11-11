#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long int64;
const int LLN = 5e2, LLM = 5e5, Mod = 1e9 + 7;
int C, N, M, D, Q;
int64 len[LLN + 5], w[LLM + 5], dis[LLN + 5][LLN + 5];
struct node
{
	int64 p, t;
};
vector<node>g[LLN + 5], h[LLM + 5];
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
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	C = read(), N = read(), M = read(), D = read(), Q = read();
	for(int i = 1; i <= M; i++)
		w[i] = read();
	for(int i = 1; i <= N; i++)
	{
		len[i] = read();
		for(int j = 1; j <= len[i]; j++)
		{
			node u, v;
			u.p = read(), u.t = read();
			v.p = i, v.t = u.t;
			h[u.p].push_back(v);
			g[i].push_back(u);
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= N; i++)
		dis[i][i] = 0;
	for(int i = 1; i <= M; i++)
	{
		for(int j = 0; j < (int)h[i].size(); j++)
		{
			for(int k = j + 1; k < (int)h[i].size(); k++)
			{
				dis[h[i][j].p][h[i][k].p] = min(dis[h[i][j].p][h[i][k].p], h[i][j].t + h[i][k].t);
				dis[h[i][k].p][h[i][j].p] = dis[h[i][j].p][h[i][k].p];
			}
		}
	}
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(Q--)
	{
		int u = read(), v = read();
		int64 Ans = 1e18;
		for(node i : h[u])
			for(node j : h[v])
				Ans = min(Ans, dis[i.p][j.p] + i.t + j.t);
		printf("%lld\n", Ans + w[u] + w[v]);
	}
	return 0;
}
