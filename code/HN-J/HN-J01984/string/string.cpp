#include <bits/stdc++.h>

using namespace std;

const int N = 201000;

int n, tot1, tot2;
pair<long long, char> a[N], c[N], d[N];
long long sum[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
		sum[i] = sum[i - 1] + a[i].first;
	}
	for (int i = 1; i <= n; i++) {
		if (sum[i] == sum[n] / 2) {
			for (int j = i; j >= 1; j--) c[++tot1] = a[j];
			for (int j = i + 1; j <= n; j++) {
				if (j == i + 1 && sum[n] % 2) a[j].first--;
				if (a[j].first) d[++tot2] = a[j];
			}
			break;
		} else if (sum[i] > sum[n] / 2) {
			long long t = sum[n] / 2 - sum[i - 1];
			c[++tot1] = make_pair(t, a[i].second);
			if (sum[n] % 2) {
				if (a[i].first - t - 1 > 0) d[++tot2] = make_pair(a[i].first - t - 1, a[i].second);
			} else {
				d[++tot2] = make_pair(a[i].first - t, a[i].second);
			}
			for (int j = i - 1; j >= 1; j--) c[++tot1] = a[j];
			for (int j = i + 1; j <= n; j++) d[++tot2] = a[j];
			break;
		}
	}
	int l = 1, r = 1;
	long long sum1 = c[1].first, sum2 = d[1].first;
	long long ans = 0;
	while (l <= tot1 && r <= tot2) {
		if (c[l].second == d[r].second) {
			if (sum1 == sum2) {
				l++, r++;
				sum1 = c[l].first;
				sum2 = d[r].first;
			} else if (sum1 < sum2) {
				sum2 -= sum1;
				l++;
				sum1 = c[l].first;
			} else if (sum1 > sum2) {
				sum1 -= sum2;
				r++;
				sum2 = d[r].first;
			}
		} else {
			if (sum1 == sum2) {
				ans += sum1;
				l++, r++;
				sum1 = c[l].first;
				sum2 = d[r].first;
			} else if (sum1 < sum2) {
				ans += sum1;
				sum2 -= sum1;
				l++;
				sum1 = c[l].first;
			} else if (sum1 > sum2) {
				ans += sum2;
				sum1 -= sum2;
				r++;
				sum2 = d[r].first;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
