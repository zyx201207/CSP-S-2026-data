#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n; long long m, a[N], pre[N];

bool check(int x)
{
	long long tot = 1e18;
	for (int i = x; i <= n; i ++)
		tot = min(tot, x * a[i] - (pre[i] - pre[i - x]));
	return tot <= m; 
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];
	
	int l = 1, r = n; 
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << "\n";
	return 0;
} 
