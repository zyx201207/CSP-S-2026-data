#include <bits/stdc++.h>

using namespace std;

#define int long long

ifstream fin("crystal.in");
ofstream fout("crystal.out");
#define cin fin
#define cout fout

const int N = 5e5 + 10;

int n, m, a[N], s[N];

bool check(int x)
{
	for (int i = 1; i + x - 1 <= n; i++)
	{
		int d = s[i + x - 1] - s[i - 1];
		int mx = a[i + x - 1];
		if (x * mx - d <= m) return true;
	}
	return false;
}

signed main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int l = 0, r = n;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
}
