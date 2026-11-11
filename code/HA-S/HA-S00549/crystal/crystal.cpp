#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

int n;
ll a[N], m;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	int ans = 1;
	ll sum = 0;
	for (int i = 1, j = 2; j <= n; j++){
		sum += (a[j] - a[j - 1]) * (j - i);
		while (sum > m && i < j) sum -= (a[j] - a[i]), i++;
		ans = max(ans, j - i + 1);
	}
	cout << ans << '\n';
	
	return 0;
}
