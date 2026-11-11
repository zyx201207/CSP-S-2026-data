#include <bits/stdc++.h>
using namespace std;

const int N = 500001;

int n, m, a[N], b[N], pos, tong[N];

int find(int x)
{
	for (int i = 1; i <= pos; ++i) if (b[i] == x) return i;
	return pos+1;
}

void aaa(int x)
{
	pos = 0;
	for (int i = x; i <= n; ++i)
	{
		int p = find(a[i]);
		if (p == pos+1) b[++pos] = a[i];
		else pos = p;
	}
	for (int i = 1; i <= pos; ++i) ++tong[b[i]];
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) aaa(i);
	for (int i = 1; i <= m; ++i) cout << tong[i] << ' ';
	return 0;
}
