#include<iostream>
using namespace std;
int n, m;
int a[500005];
int o[500005];
int p[300005];
int q[300005];
int t, s;
bool flag = true;
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (flag) {
			if (a[i] < a[i-1]) flag = false;
			else if (a[i] >= a[i-1]) p[a[i]] = i;
		}
	}
	if (flag) {
		for (int i = 1; i <= m; i++) {
			printf ("%d ", p[i]);
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i-1]) {
			if (s) {
				for (int j = 1; j <= t; j++) {
					q[o[j]]+=s;
				}
			}
			s = 0;
			t = 0;
			for (int j = i; j <= n; j++) {
				for (int k = t; k >= 1; k--) {
					if (o[k] == a[j]) {
						t = k-1;
						break;
					}
				}
				t++;
				o[t] = a[j];
			}
			for (int j = 1; j <= t; j++) {
				q[o[j]]++;
			}
		}
		else s++;
	}
	for (int i = 1; i <= m; i++) {
		printf ("%d ", q[i]);
	}
	return 0;
}
