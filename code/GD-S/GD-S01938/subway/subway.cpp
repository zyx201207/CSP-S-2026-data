#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5,maxn = 5e2 + 5;
const long long inf = (1ll << 60);
int w[MAXN];
struct Tim//每个站台到那条线的时间
{
	int Id,tim;//线的编号和时间
};
vector <Tim> t[MAXN];
long long e[maxn][maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,D,Q;
	cin >> C >> n >> m >> D >> Q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1,K,stat,val; i <= n; i++)
	{
		cin >> K;
		for (int j = 1; j <= K; j++)//这条线的第j个站是stat
		{
			cin >> stat >> val;
			t[stat].push_back((Tim){i,val});
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			e[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; i++) e[i][i] = 0;
	for (int i = 1,siz,u,v,val; i <= m; i++)
	{
		siz = t[i].size();
		for (int j = 0; j < siz; j++)
		{
			for (int k = 0; k < siz; k++)
			{
				if (j == k) continue;
				u = t[i][j].Id,v = t[i][k].Id,val = t[i][j].tim + t[i][k].tim;
				e[u][v] = e[v][u] = min(e[u][v],1ll * val);
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				e[i][j] = min(e[i][j],e[i][k] + e[k][j]);
			}
		}
	}
	int St,En;
	long long ans;
	while (Q--)
	{
		ans = inf;
		cin >> St >> En;
		for (Tim i : t[St])
		{
			for (Tim j : t[En])
			{
				ans = min(ans,e[i.Id][j.Id] + 1ll * i.tim + 1ll * j.tim + 1ll * w[St] + 1ll * w[En]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
