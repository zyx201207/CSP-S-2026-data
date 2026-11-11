#include <bits/stdc++.h>
using namespace std;
struct Node
{
	long long pos;
	long long step;
	Node()
	{
		pos = 0;
		step = 0;
	}
};
int mmap[500][500];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long c = 0, n = 0, m = 0, d = 0, q = 0;
	cin >> c >> n >> m >> d >> q;
	vector< int > w(m);
	vector< vector< int > > t(n + 1);
	for (int i = 0; i < m ; ++i)
		cin >> w[i];
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		cin >> k;
		t[i].resize(n + 1);
		for (int j = 0; j < k; ++j)
		{
			int a1 = 0, t1 = 0;
			cin >> a1 >> t1;
			t[i][a1] = t1;
		}
		for (int j = 0; j < k; ++j)
			for (int l = 0; l < k; ++l)
				mmap[j][l] = min(mmap[j][l], w[j] + w[l] + t[i][j] + t[i][l]);
	}
	for (int i = 0; i < q; ++i)
	{
		int u = 0, v = 0;
		cin >> u >> v;
		cout << mmap[u][v] << '\n';
	}
	return 0;
}
