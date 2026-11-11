#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL n, m, cnt = 0, a[500005], b[500005];

LL check(LL x) {
	
	LL cnt = 0, ans = 0, j = x - 1;
	
	for (int i = 1; i < x; i ++) {
		if (i != x)
			b[i] = a[x]- a[i];
		else 
			b[i] = 0x3f3f3f3f3f3f3f3f;
//		cout << b[i] << ' ';
	}
//	cout << endl;
	
	while (j > 0 && cnt + b[j] <= m) {
		
		cnt += b[j];
		ans ++;
		j --;
	}
	
	return ans;
}

int main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	LL ans = 0;
//	for (int i = 1; i <= n; i ++) {
//		ans = max(ans, check(i) + 1);
//	}
	
	for (int i = 1, j = 1, cnt = 0; i <= n; i ++) {
		cnt += (i - j) * (a[i] - a[i - 1]);
		while (j <= i && cnt > m) {
			cnt -= a[i] - a[j ++];
		}
		ans = max(ans, 1LL * (i - j + 1));
	}
	
	cout << ans << endl;
	
	return 0;
} 
