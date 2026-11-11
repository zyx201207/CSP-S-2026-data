#include <bits/stdc++.h>
using namespace std;

long long n, m, ans;
long long arr[200010];

void dfs(long long dep, long long cnt, long long num) {
	if(cnt == m) {
		ans = max(ans, num);
		return;
	}
	if(dep > n) {
		return;
	}
	
	if(cnt == 0) {
		dfs(dep + 1, cnt + 1, arr[dep]);
	}
	else {
		dfs(dep + 1, cnt + 1, num & arr[dep]);
	}
	dfs(dep + 1, cnt, num);
	return;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	if(m == 1) {
		for(int i = 1; i <= n; i++) {
			ans = max(ans, arr[i]);
		}
	}
	else if(m == n) {
		ans = arr[1];
		for(int i = 2; i <= n; i++) {
			ans = ans & arr[i];
		}
	}
	else {
		dfs(1, 0, 0);
	}
	printf("%lld\n", ans);
	return 0;
}
