#include <algorithm>
#include <iostream>

using namespace std; 

const int N = 5e5 + 10;
int n, m, ans = 1;
long long a[N], s[N];

int calc(int i, int x) {
	int l = 1, r = i - 1, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (x < a[i] * (i - mid) - (s[i - 1] - s[mid - 1])) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	return ans;
}

int main() { 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	
	for (int i = 2; i <= n; i ++) 
		ans = max(ans, i - calc(i, m));
	cout << ans << '\n';
	
	return 0;
}
