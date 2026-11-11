#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010], s[500010], f[500010]; 
int main() {
	//priority
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int k = 0, c = 0;
	for(int i = 1; i <= n;i++) {
		if(a[i] != a[i - 1]) {
			f[k] = c;
			s[k] = a[i - 1];
			c = 0;
			k++;
		}
		c++;
	}
	if(c != 0) {
		f[k] = c;
		s[k] = a[n];
	}
	ll l = 1, cnt = 0, sum = 0;
	ll maxn = 0, res = 0;
	for(int i = 1; i <= k; i++) {
		cnt += sum * (s[i] - s[i - 1]);
		while(cnt > m) {
			cnt -= f[l] * (s[i] - s[l]);
			sum -= f[l];
			l++;
		}
		//printf("%d %lld %lld %lld %lld\n", i , l, cnt, sum, res);
		res = 0;
		ll x = 0;
		for(int j = 1;l != 1&& cnt + x <= m && j <= f[l]; j++) {
			x += s[i] - s[l - 1];
			res++;
		}
		if(res && cnt + x > m) res--; 
		x -= s[i] - s[l];
		maxn = max(maxn, res + sum + f[i]);
		//printf("%d %lld %lld %lld %lld\n", i , l, cnt, sum, res);
		sum += f[i];
	}
	printf("%lld", maxn);
	return 0;
}
