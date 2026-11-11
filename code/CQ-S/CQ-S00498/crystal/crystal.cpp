#include<cstdio>
#include<algorithm>
int constexpr N = 5e5 + 1;
long long seq[N], dif[N], dp[N], n, m, res, p;
long long max(long long a, long long b) {
	return a > b ? a : b;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n;i++) {
		scanf("%lld", &seq[i]);
	}
	std::sort(seq + 1, seq + n + 1, [&](long long a, long long b) -> bool {
		return a < b;
	});
	for(int i = 1;i <= n;i++) {
		dif[i] = seq[i] - seq[i - 1];
	}
	int pos1 = 1, pos2 = 1, r = 1;
	while(pos2 <= n) {
		p += dif[pos2] * (pos2 - pos1);
		//printf("%d, %d: %d\n", pos1, pos2, p);
		while(p > m) {
			p -= seq[pos2] - seq[pos1];
			pos1++;
			r--;
		}
		res = max(res, r);
		pos2++, r++;
	}
	printf("%lld", res);
	return 0;
}
