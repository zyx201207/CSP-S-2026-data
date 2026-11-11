#include <bits/stdc++.h>
#define N 410
using namespace std;

int c, n, m, d, q;
int k[N];
int w[N];
int a[N][N], t[N][N];
bool inl[N][N];
int s[N], e[N];
int min_t = INT_MAX;
bool visit[N];
int _a[N][N];

void dfs(int now, int time, int num)
{
	//~ if (line == -1)
		//~ time += w[now];
	if (now == e[num])
	{
		//~ cout  << "aa" << time << '\n';
		min_t = min(min_t, time);
		return;
	}
	for (int i = 1; i <= n; i++)
		if (inl[i][now])
		{
			for (int j = 1; j <= k[i]; j++)
				if (now != a[i][j] && !visit[a[i][j]])
				{
					visit[a[i][j]] = true;
					//~ cout << "from " << now << " to " << a[i][j] << " in " << i << "\n";
					//~ cout << time << ' ' << i << "\n";
					dfs(a[i][j], time + t[i][j] + t[i][_a[i][now]], num);
					visit[a[i][j]] = false;
				}
		}
}

int main()
{
	freopen("subway.in",  "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			_a[i][a[i][j]] = j;
			inl[i][a[i][j]] = true;
		}
	}
	//~ for (int i = 1; i <= n; i++)
	//~ {
		//~ for (int j = 1; j <= k[i]; j++)
			//~ cout << t[i][j] << ' ';
		//~ cout << "\n";
	//~ }
	for (int i = 1; i <= q; i++)
		cin >> s[i] >> e[i];
	for (int i = 1; i <= q; i++)
	{
		memset(visit, false, sizeof visit);
		min_t = INT_MAX;
		dfs(s[i], 0, i);
		cout << min_t + w[e[i]] + w[s[i]] << "\n";
	}
	return 0;
}
