#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c, n, m, d, q, k, a, t, s, x, y, w[500005], zs, mi[502][502];
bitset<5100> f;
vector<pair<int, int>> v[500005], dv[500005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(i!=j)mi[i][j] = LLONG_MAX;
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		cin >> k;
		while(k--)
		{
			cin >> a >> t;
			for(auto j : v[a])
			{
				mi[i][j.first] = min(mi[i][j.first], j.second + t);
				mi[j.first][i] = min(mi[j.first][i], j.second + t);
			}
			v[a].push_back({i, t});
		} 
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(mi[i][j] != LLONG_MAX && i != j)
			{
				dv[i].push_back({j, mi[i][j]});
				mi[i][j] = LLONG_MAX;
			}
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>> q;
		q.push({0, i});
		f.reset();
		while(q.size())
		{
			int ls = q.top().second;
			q.pop();
			if(f[ls])continue;
			f[ls] = 1;
			for(auto j : dv[ls])
			{
				if(mi[i][j.first] > mi[i][ls] + j.second)
				{
					mi[i][j.first] = mi[i][ls] + j.second;
					q.push({mi[i][j.first], j.first});
				}
			}
		}
	}
	while(q--)
	{
		cin >> x >> y;
		ll ans = LLONG_MAX;
		for(auto i : v[x])
		{
			for(auto j : v[y])
			{
				if(mi[i.first][j.first] != LLONG_MAX)ans = min(ans, mi[i.first][j.first] + i.second + j.second);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
