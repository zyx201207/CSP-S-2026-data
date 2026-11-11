#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int Mx = 5e5 + 5;
const int Nx = 505;

struct psw
{
	int toi, ta;
} ;

int cc, n, m, d, q;
int w[Mx];
vector<psw> ak[Mx];
long long dis[Nx][Nx];
int tmpid[25], tmpta[25];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> cc >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1, k; i <= n; ++i)
	{
		cin >> k;
		for (int j = 1, a, t; j <= k; ++j)
		{
			cin >> a >> t;
			ak[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dis[i][j] = 2e18;
	for (int i = 1; i <= n; ++i)
		dis[i][i] = 0;
	for (int i = 1; i <= m; ++i)
	{
		int di = ak[i].size();
		for (int j = 1; j <= di; ++j)
		{
			tmpid[j] = ak[i][j - 1].toi;
			tmpta[j] = ak[i][j - 1].ta;
		}
		for (int d = 1; d <= di; ++d)
			for (int e = d + 1; e <= di; ++e)
			{
				dis[tmpid[e]][tmpid[d]] = dis[tmpid[d]][tmpid[e]] = min(dis[tmpid[d]][tmpid[e]], 
					0ll + tmpta[d] + tmpta[e]);
			}
		
	}
	for (int dk = 1; dk <= n; ++dk)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][dk] + dis[dk][j]);

	while (q--)
	{
		int u, v;
		cin >> u >> v;
		long long ans = 2e18;
		for (psw kt : ak[u])
			for (psw kh : ak[v])
			{
				int frn = kt.toi, edn = kh.toi;
				int fra = kt.ta, eda = kh.ta;
				long long res = dis[frn][edn] + fra + eda;
				ans = min(ans, res);
			}
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
}