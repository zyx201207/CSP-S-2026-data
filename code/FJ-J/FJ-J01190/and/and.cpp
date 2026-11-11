#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, a[N];
int c[N][35], b[35];
bool flag[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int tmp = a[i], cnt = 0;
		while (tmp != 0) {
			c[i][cnt] = tmp % 2;
			cnt++;
			tmp /= 2;
		}
	}
	for (int i = 0; i < 35; i++)
		for (int j = 1; j <= n; j++)
			if (c[j][i] == 1) b[i]++;
	memset(flag, true, sizeof flag);
	for (int i = 35; i >= 0; i--) {
		if (b[i] >= m) {
			for (int j = 1; j <= n; j++) {
				if (c[j][i] == 0 && flag[j] == 1) {
					flag[j] = false;
					for (int k = i - 1; k >= 0; k--)
						b[k] -= c[j][k];
				}
			}
		}
	}
	int cnt = m;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		if (flag[i] == 1 && cnt != 0) {
			if (cnt != m)
				ans = (ans & a[i]);
			else
				ans = a[i];
			cnt--;
		}
	printf("%lld", ans);
	return 0;
}
