#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll c, n, m, d, q;
ll ans = 0;
const ll MX1 = 1e15;
const ll MX2 = 1e18;
const int MX3 = 1e5;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	ll k;
	
	vector<ll> a[MX1];
	ll t1[MX2];
	ll t2[500][500000];
	ll jh[MX3][2];
	for (int i = 0; i < m; ++i)
	{
		cin >> t1[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> k;
		for (int j = 0; j < k; ++j)
		{
			cin >> t2[i][j];
			a[t2[i][j]].push_back[i];
		}
	}
	for (int i = 0; i< q ++i)
	{
		cin >> jh[i][0] >> jh[i][1];
	}
	for (int i = 0; i<q; ++i)
	{
		
	}
	
	
	
	//cout << ans;
	
	return 0;
}
