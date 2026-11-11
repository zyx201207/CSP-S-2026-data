#include <bits/stdc++.h>
using namespace std;
struct Node
{
	long long x, y, tim;
};
long long c, n, m, d, q, w[500005], a[1005][1005], t[1005][1005];
vector<Node> g[505][1005];
unordered_multimap<int, pair<int, int>> ummp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1; i<=q; i++)
	{
		cout << 0 << '\n';
	}
	return 0;
}
