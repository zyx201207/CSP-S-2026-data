#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	static int a[500001];
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	sort(a + 1, a + n + 1, greater<int>());
	
	int res = 0;
	
	int i = 1, j = 1;
	long long sum = 0;
	while (j < n)
	{
		sum += a[i] - a[++j];
		
		while (sum > m)
		{
			sum -= (a[i] - a[i + 1]) * (j - i);
			++i;
		}
		
		res = max(res, j - i + 1);
	}
	
	cout << res << '\n';
	
	return 0;
}
