#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

using ll = long long;
using pil = pair<int, ll>;

const ll N = 2e6 + 5, M = 5005;

int n, m, d, q;
ll w[N], t, mp[M][M], ans;
vector<pil> vec[N];

void init() {}

void solve()
{
	cin >> m >> n >> d >> q;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= m; ++j)
			mp[i][j] = i == j ? 0 : 1e18;
	}
	for (int i = 1, k; i <= m; ++i)
	{
		cin >> k;
		for (int x; k--;)
		{
			cin >> x >> t;
			vec[x].emplace_back(i, t);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (auto [j, w1] : vec[i])
		{
			for (auto [k, w2] : vec[i])
			{
				if (j != k)
					mp[j][k] = min(mp[j][k], w1 + w2);
			}
		}
	}
	for (int k = 1; k <= m; ++k)
	{
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= m; ++j)
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
		}
	}
	for (int x, y; q--;)
	{
		cin >> x >> y;
		ans = 1e18;
		for (auto [i, w1] : vec[x])
		{
			for (auto [j, w2] : vec[y])
				ans = min(ans, w1 + mp[i][j] + w2);
		}
		cout << ans + w[x] + w[y] << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	// freopen("subway.err", "w", stderr);
	int _ = 1, __;
	cin >> __;
	init();
	while (_--)
		solve();
	return 0;
}
/*
g++ subway.cpp -o subway.exe -std=c++14 -O2
*/
/*
话说你们知道吗，这场全是原题，搬了 CSP-S 2026 呢（
梦熊的模拟赛好龙啊，质量差还全是搬的，只要看到出题人是 cute_lbw 就知道这场没有做的必要了
正睿质量还行，但是二十连也是搬的，而且通常数据可能比大样例还水
不想打模拟赛，gpt 6.1 sol 组一套题都比这两个好吧
*/