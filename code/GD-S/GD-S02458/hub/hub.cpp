#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int N(2e6 + 5);
struct road
{
	int v, w;
	road() {}
	road(const int &v, const int &w) : v(v), w(w) {}
	bool operator<(const road &b) const
	{
		return b.w > w;
	}
};
vector<road> v[N];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int c, t;
	cin >> c >> t;
	for (int i = 1, n, k; i <= t; i++)
	{
		cin >> n >> k;
		for (int j = 1, ui, vi; j < n; j++)
		{
			cin >> ui >> vi;
			v[ui].emplace_back(vi, 0);
			v[vi].emplace_back(ui, 0);
		}
		if (k % 2)
		{
			cout << 2 << '\n';
		}
		else
		{
			cout << 1 << '\n';
		}
	}
	return 0;
} 
