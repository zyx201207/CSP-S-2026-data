#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t--)
	{
		int n, ans = 0;
		ll d;
		cin >> n >> d;
		vector<ll> x(n);
		for(int i = 0; i < n; i++) cin >> x[i];
		cout << (x[n - 1] - x[0]) / d << '\n';
	}
	return 0;
}

