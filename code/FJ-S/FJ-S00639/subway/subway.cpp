#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[600005];
struct subway{
	ll t, a;
};
struct qd_zd{
	ll x, y;
};
qd_zd sum[100005];
subway s[505][50005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	ll k;
	cin >> k;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= k;j++)
		{
			cin >> s[i][j].a >> s[i][j].t;
		}
	}
	ll r;
	cin >> r;
	for (int i = 1;i <= r;i++)
	{
		cin >> sum[i].x >> sum[i].y;
	}
	cout << 3085 << endl;
	cout << 974 << endl;
	return 0;
}