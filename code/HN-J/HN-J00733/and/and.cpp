#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e5 + 10;
int a[N];

bool cmp(int a, int b)
{
	return a > b;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	int maxx = INT_MIN;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n - m; i ++)
	{
		int ans = a[i] & a[i + m - 1];
		maxx = max(maxx, ans);
	}
	cout << maxx << endl;
	return 0;
}

