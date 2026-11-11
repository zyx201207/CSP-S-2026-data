#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, k; cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	vector< pair<int,int> > a, t, plan(q + 1), g;
	for(int i = 1; i <= m; i++) cin >> w[i];
	while(n--)
	{
		cin >> k;
		a.resize(k + 1); t.resize(k + 1);
		for(int i = 1; i <= k; i++)
		{
			int p, q; cin >> p >> q;
			a[i].first = p; t[i].first = q;
			a[i].second = i; t[i].second = i;
		}
	}
	for(int i = 1; i <= q; i++) cin >> plan[i].first >> plan[i].second;
	for(int i = 1; i <= q; i++)
	{
		cout << w[plan[i].first] + w[plan[i].second] + t[plan[i].first].first + t[plan[i].second].first << '\n';
	}
	return 0;
}

