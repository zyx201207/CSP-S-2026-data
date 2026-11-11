#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
const int N = 2e5 + 10;
int arr[N][40];
bool f[N];

void er(ll x, int line) {
	int p = 30;
	while (x != 0) {
		arr[line][p] = x % 2;
		x /= 2;
		p--;
	}
}

ll shi(int line) {
	ll t = 1;
	ll r = 0;
	for (int i = 30; i >= 1; i--) {
		r += arr[line][i] * t;
		t *= 2;
	}
	return r;
}

void ceShi() {
	for (int i = 1; i <= n; i++) {
		printf("%d: ", i);
		for (int j = 1; j <= 30; j++) {
			printf("%d", arr[i][j]);
		}
		printf("  %d\n", f[i]);
	}
	printf("\n\n");
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		er(x, i);
	}
	//ceShi();
	for (int k = 1; k <= 30; k++) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (f[i] == 0 && arr[i][k] == 1) {
				cnt++;
			}
		}
		if (cnt >= m) {
			for (int i = 1; i <= n; i++) {
				if (f[i] == 0 && arr[i][k] == 0) {
					f[i] = 1;
				}
			}
		}
	}
	//ceShi();
	int r = -1;
	for (int i = 1, j = 1; i <= n && j <= m; i++) {
		if (f[i] == 0) {
			if (r == -1) {
				r = shi(i);
			} else {
				r &= shi(i);
			}
			j++;
		}
	}
	printf("%d", r);
	
	return 0;
}
