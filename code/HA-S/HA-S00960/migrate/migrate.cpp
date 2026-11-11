#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int c, t;

int n, d;

long long x[2000010];

long long ans = 0;

int main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	c = read(), t = read();
	while(t--) {
		n = read(), d = read();
		memset(x, 0, sizeof(x));
		ans = 0;
		for(int i = 1; i <= n; i++) {
			x[i] = read();
		}
		long long dm = x[2] - x[1];
		for(int i = 1; i <= n; i++) {
			if(dm * i <= d) {
				ans += (n - i);
			}
		}
		cout << ans <<"\n";
	}
	
	return 0;
}
