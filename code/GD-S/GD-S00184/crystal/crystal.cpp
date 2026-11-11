#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 5e5 + 5;

int n;
ll m;
array<ll, N> a;
vector<pair<ll, int>> ve;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], ve.emplace_back(a[i], i);
	sort(ve.begin(), ve.end());
	int ans = 0;
	ll sum = 0; 
	ll totc = 1;
	int nowi = 0;
	for (int i = 0; i < ve.size(); i++)
	{
		while (sum > m)
		{
			// erase nowi
			sum -= (ve[i].first - ve[nowi].first);
			totc--;
			nowi++;
		}
		ans = max(ans, (int)totc);
		if (i + 1 < ve.size())
		{
			sum += totc * (ve[i + 1].first - ve[i].first); 
			totc++;
		}
	}
	cout << ans << "\n";
	return 0; 
}
