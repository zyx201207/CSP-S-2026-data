#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5E5+5;
int n, m, a[MAXN], sum[MAXN];
int ans;
bool flag = false;

signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for (int i = 2; i <= n; i ++) {
		sum[i] = sum[i-1] + (a[i] - a[i-1]) * (i-1);
	}	
	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (sum[i] - sum[j-1] == m) {
				ans = max(ans, i - j + 1);
			}
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}
