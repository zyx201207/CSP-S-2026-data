#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N] = {};
bool cmp(int a, int b)
{
	return a > b;
}
signed main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)  cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	int ans = a[1];
	for(int i = 2; i <= m; ++i)
	{
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
