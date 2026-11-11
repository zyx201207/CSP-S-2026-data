#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	scanf("%lld%lld", &n, &m);
	vector<long long>a(n + 1);
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	vector<long long>cnt(m + 1);
	for (long long i = 1; i <= n; i++) {
		vector<long long>table(n + 1, -1);
		vector<long long>appear(m + 1, -1);
		long long nxt_pos = 1;
		for (long long j = i; j <= n; j++) {
			if (appear[a[j]] != -1) {
				long long temp = appear[a[j]];
				for (long long k = appear[a[j]]; k <= nxt_pos; k++) {
					appear[table[k]] = -1;
					table[k] = -1;
				}
				nxt_pos = temp;
			}
			table[nxt_pos] = a[j];
			appear[a[j]] = nxt_pos;
			nxt_pos++;
		}
		for (long long j = 1; j < nxt_pos; j++) {
			for (long long k = 1; k <= m; k++) {
				if (table[j] == k) {
					cnt[k]++;
				}
			}
		}
		continue;
	}
	for (long long i = 1; i <= m; i++) {
		printf("%lld ", cnt[i]);
	}
	printf("\n");
	return 0;
}
