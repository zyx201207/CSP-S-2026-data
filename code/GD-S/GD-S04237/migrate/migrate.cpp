#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
const ll NN = 2e17 + 5;
ll c, t, n[N], d[N], xxx[NN];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	for(ll i = 0; i < t; i++)
	{
		cin >> n[i] >> d[i];
		for(ll j = 0; j < d[i] ; j++)
		{
			cin >> xxx[i];
		}
	}
	for(ll i = 0; i < t; i++)
	{
		cout << d[i];
	}
	return 0;
}
