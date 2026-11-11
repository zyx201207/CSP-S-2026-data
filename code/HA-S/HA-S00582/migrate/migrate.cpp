#include <bits/stdc++.h>
#define intt long long
using namespace std;
intt n, d;
vector<intt> a;
unordered_map<intt, pair<intt, intt> > mp;
intt Hash(intt x, intt y)
{
	return x * 1e9 + y;
}
pair<intt, intt> check(intt l, intt r, intt d)
{
	if (mp.find(Hash(l, r)) != mp.end()) return mp[Hash(l, r)];
	if (a[r] - a[l] <= d) return {1, 1};
	int minnum = 1e9, cnt = 1;
	for (intt i = l + 1; i < r; i++)
	{
		if (a[i] - a[l] <= d)
		{
			auto now = check(i, r, d); now.first++;
			if (minnum > now.first) minnum = now.first, cnt = now.second;
			else if (minnum == now.first) minnum = now.first, cnt += now.second;
		}
	}
	mp[Hash(l, r)] = {minnum, cnt};
	return {minnum, cnt};
}
void solve()
{
	intt ans = 0;
	cin >> n >> d;
	a.clear(); a.push_back(0);
	mp.clear();
	for (intt i = 1, x; i <= n; i++) cin >> x, a.push_back(x);
//	for (intt i = 1; i <= n; i++) cout << a[i] << ' ';
//	cout << '\n';
	for (intt i = 1; i <= n; i++)
	{
		for (intt j = i + 3; j <= n; j++)
		{
			auto res = check(i, j, d);
			if (res.second == 2) ans++;
		}
	}
	cout << ans << '\n';
}
void solve2()
{
	intt ans = 0;
	cin >> n >> d;
	a.clear(); a.push_back(0);
	for (intt i = 1, x; i <= n; i++) cin >> x, a.push_back(x);
	if (n < 4)
	{
		cout << "0\n";
		return;
	}
	int p = d / (a[2] - a[1]);
	if (p <= 1)
	{
		cout << "0\n";
		return;
	}
	for (int i = 1; i + p * 2 - 1 <= n; i++) ans++;
	cout << ans << '\n';
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	freopen("migrate3.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c, t;
	cin >> c >> t;
	if (c <= 10) while (t--) solve();
	else if (c <= 12) while (t--) solve2();
	return 0;
}
