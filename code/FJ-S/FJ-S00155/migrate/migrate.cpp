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
bool solve(vector< long long > a, long long n, long long l, long long r, long long d);
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long c = 0, t = 0;
	cin >> c >> t;
	while (t--)
	{
		long long n = 0, d = 0, cnt = 0;
		cin >> n >> d;
		vector< long long > a(n);
		for (long long i = 0; i < n; ++i)
			cin >> a[i];
		for (long long i = 0; i < n; ++i)
			for (long long j = i + 1; j < n; ++j)
				if (solve(a, n, i, j, d))
					++cnt;
		cout << cnt << '\n';
	}
	return 0;
}
bool solve(vector< long long > a, long long n, long long l, long long r, long long d)
{
	queue< Node > k;
	queue< Node > s;
	Node fst;
	fst.pos = l;
	fst.step = 0;
	k.push(fst);
	while(!k.empty())
	{
		queue< Node > k_k = k;
		k = s;
		int cnt = -1;
		while(!k_k.empty())
		{
			Node now = k_k.front();
			k_k.pop();
			if (now.pos == r)
				++cnt;
			else
			{
				Node temp;
				temp.step = now.step + 1;
				for (int i = 1; a[now.pos + i] - a[now.pos] <= d && now.pos + i <= r; ++i)
				{
					temp.pos = now.pos + i;
					k.push(temp);
				}
			}
		}
		if (cnt != -1)
			if (cnt == 1)
				return true;
			else
				return false;
	}
	return false;
}
