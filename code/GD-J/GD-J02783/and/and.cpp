#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e5 + 5;
int n, m, a[maxn], choosen[maxn], ans = 0;
bool flag = true;

void DFS(int pos, int chose) {
	if(chose == m) {
		int res = LLONG_MAX;
		for(int i = 0; i < chose; i++) {
			res &= choosen[i];
		} 
		ans = max(ans, res);
		return;
	}
	if(pos > n) return;
	DFS(pos + 1, chose);
	choosen[chose] = a[pos];
	DFS(pos + 1, chose + 1);
	choosen[chose] = 0;
}

bool check(int num) {
	for(int i = 0; i <= 30; i++) {
		if(num == ((long long)1 << i)) return true;
	} 
	return false;
}

signed main() {
	(void)freopen("and.in", "r", stdin);
	(void)freopen("and.out", "w", stdout);
	(void)scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		(void)scanf("%lld", &a[i]);
		if(!check(a[i] + 1)) flag = false;
	}
	if(n <= 20) {
		DFS(1, 0);
		(void)printf("%lld", ans);
		return 0;
	}
	if(m == 1) {
		for(int i = 1; i <= n; i++) {
			ans = max(ans, a[i]);
		}
		(void)printf("%lld", ans);
		return 0;
	}
	if(m == n) {
		int res = LLONG_MAX;
		for(int i = 1; i <= n; i++) {
			res &= a[i];
		}
		(void)printf("%lld", res);
		return 0;
	}
	if(flag) {
		int res = LLONG_MAX;
		sort(a + 1, a + 1 + n);
		for(int i = n; i >= (n - m + 1); i--) {
			res &= a[i];
		}
		(void)printf("%lld", res);
		return 0;
	}
	if(m == (n - 1)) {
		int res = LLONG_MAX;
		for(int i = 1; i <= n; i++) {
			res &= a[i];
		}
		for(int i = 1; i <= n; i++) {
			ans = max(ans, (res & (~a[i])));
		}
		(void)printf("%lld", ans);
		return 0;
	}
	if(m == 2) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				ans = max(ans, (a[i] & a[j]));
			}
		}
		(void)printf("%lld", ans);
		return 0;
	}
	(void)printf("0"); 
	return 0;
}
