#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;

long long solveB(int x, int y);
vector<vector<int>> a, t;
vector<vector<pair<int, long long>>> lines;
vector<long long>	w, k;
long long solve(int x, int y);


signed main()
{
	ifstream cin("subway.in");
	ofstream cout("subway.out");


	ios::sync_with_stdio(0), cin.tie(0);


	cin >> c >> n >> m >> d >> q;
	w.resize(m + 1), k.resize(n + 1);
	for (int i = 1; i <= m; ++i)
	{
		cin >> w[i];
	}
	a.resize(n + 1), t.resize(n + 1);
	lines.resize(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> k[i];
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; ++j)
		{
			cin >> a[i][j] >> t[i][j];
			lines[a[i][j]].push_back({ i, t[i][j] });
		}
	}

	while (q--)
	{
		int x, y;
		cin >> x >> y;
		if (x == y)
		{
			cout << "0\n";
		}

		if (c >= 12 && c <= 19)
		{
			cout << solveB(x, y) << '\n';
			continue;
		}
		cout << solve(x, y) << '\n';
	}

}

vector<bool>visp, visl;
vector<long long>dis;

long long solve(int x, int y)
{
	visp.resize(m + 1, 0), dis.resize(m + 1, ((long long)numeric_limits<int>::max()) * 2);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
	pq.push({ 0, x});
	dis[x] = 0;
	for (int i = 1; i <= m; ++i)
	{
		visp[i] = 0;
		dis[i] = ((long long)numeric_limits<int>::max()) * 2;
	}
	while (pq.size())
	{
		auto [nowdis, u] = pq.top();
		pq.pop();
		if (visp[u])
		{
			continue;
		}
		visp[u] = 1;
		//cerr << u << ' ' << nowdis << '\n';
		if (u == y)
		{
			break;
		}
		for (auto [line, time] : lines[u])
		{
			for (int i = 1; i <= k[line]; ++i)
			{
				int nxtdis = nowdis + time + t[line][i];
				//cerr << a[line][i] << ' ' << nxtdis << ' ' << dis[a[line][i]] << '\n';
				if (nxtdis < dis[a[line][i]])
				{
					dis[a[line][i]] = nxtdis;
					pq.push({ nxtdis, a[line][i]});
				}
			}
		}
	}
	return dis[y] + w[x] + w[y];
}

long long solveB(int x, int y)
{
	visp.resize(m + 1, 0), dis.resize(m + 1, ((long long)numeric_limits<int>::max()) * 2);
	queue<pair<long long, int>>pq;
	pq.push({ 0, x });
	dis[x] = 0;
	for (int i = 1; i <= m; ++i)
	{
		visp[i] = 0;
		dis[i] = ((long long)numeric_limits<int>::max()) * 2;
	}
	while (pq.size())
	{
		auto [nowdis, u] = pq.front();
		pq.pop();
		if (u == y)
		{
			break;
		}
		for (auto [line, time] : lines[u])
		{
			for (int i = 1; i <= k[line]; ++i)
			{
				int nxtdis = nowdis + time + t[line][i];
				if (nxtdis < dis[a[line][i]] && !visp[a[line][i]])
				{
					dis[a[line][i]] = nxtdis;
					pq.push({ nxtdis, a[line][i] });
					visp[a[line][i]] = 1;
				}
			}
		}
	}
	return dis[y] + w[x] + w[y];
}