#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, ll>
#define vi vector<int>
#define i128 __int128
using namespace std;
const int maxm = 5e5 + 5, maxn = 505;
const ll INF = 1e18;
int c, n, m, d, q;
ll w[maxm], trans[maxn][maxn];
vector<PII> gil[maxm];
vector<PII> pos[maxm];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) trans[i][j] = INF;
	for(int i = 1; i <= n; i++)
	{
		trans[i][i] = 0;
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) 
		{
			int x, ti;
			cin >> x >> ti;
			gil[x].emplace_back(i, w[x] + ti);
			pos[x].emplace_back(i, ti);
		}
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j < pos[i].size(); j++)
		{
			for(int k = j + 1; k < pos[i].size(); k++)
			{
				int x = pos[i][j].first, y = pos[i][k].first;
				trans[x][y] = trans[y][x] = min(trans[x][y], pos[i][j].second + pos[i][k].second);
			}
		}
	}
	for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) trans[i][j] = min(trans[i][j], trans[i][k] + trans[k][j]);
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		ll ans = INF;
		for(auto tmp: gil[x])
		{
			int i = tmp.first;
			ll wi = tmp.second;
			for(auto nxt: gil[y])
			{
				int j = nxt.first;
				ll wj = nxt.second;
				ans = min(ans, wi + wj + trans[i][j]); 
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

