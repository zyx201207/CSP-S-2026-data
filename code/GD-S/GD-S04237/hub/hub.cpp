#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
ll c, t, n, k, u[N], v[N];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	for(ll i = 0; i <= t; i++)
	{
		cin >> n >> k;
		for(ll j = 0; j <= t; j++)
		{
			cin >> u[j] >> v[j];
		}
	}
	for(ll i = 0; i <= t; i++) cout << k;
	return 0;
}
