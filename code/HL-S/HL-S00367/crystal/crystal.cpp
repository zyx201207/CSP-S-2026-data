#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
long long a[N], c[N];
long long n, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	long long ans = 0;
	sort(a + 1, a + n + 1);
	for(long long i = 2; i <= n; i ++) {
		long long u = m;
		for(long long j = 1; j < i; j ++) {
			c[j] = abs(a[i] - a[j]);
		}
		long long cnt = 0;
		sort(c + 1, c + i);
		for(long long j = 1; j <= i; j ++) {
			if(u >= c[j]) u -= c[j];
			else break;
			cnt ++;
		}
		ans = max(ans, cnt);
		memset(c, 0, sizeof(c));
	}
	cout << ans << endl;
	return 0;
}
