#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 6e5 + 55;
int n, m, a[N];
int num[N], nex[N], b[N];
int f = 0;

inline int read() {
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		ch = getchar();
	}

	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}

	return x;
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	n = read();
	m = read();
	for(int i = 1; i <= n; i ++)  {
		a[i] = read();
		if(a[i] < a[i - 1]) {
			f = 1;
		}
	}

	if(f == 0) {
		for(int i = 2; i <= n; i ++) {
			if(a[i] != a[i - 1]) {
				num[a[i - 1]] = i * (i - 1) / 2;
			}
		}

		for(int i = 1; i <= m; i ++) {
			cout << num[i] << ' ';
		}
		
		return 0;
	}

	for(int i = n; i >= 1; i --) {
		if(b[a[i]]) {
			nex[i] = b[a[i]];
		} else {
			b[a[i]] = i;
		}
		
		if(nex[i]) {
			f = 1;
		}
	}
	
	if(f == 0) {
		for(int i = 2; i <= n; i ++) {
			if(a[i] != a[i - 1]) {
				num[a[i - 1]] = i * (i - 1) / 2;
			}
		}

		for(int i = 1; i <= m; i ++) {
			cout << num[i] << ' ';
		}
		
		return 0;
	}

//	for(int i = 1; i <= n; i ++) cout << nex[i] << ' ';

	for(int i = 1; i <= n; i ++) {
		int j = i;
		num[a[j]] ++;
		while(j <= n) {
			if(nex[j]) {
				j = nex[j];
			} else {
				j ++;
				num[a[j]] ++;
			}
		}
	}

	for(int i = 1; i <= m; i ++) {
		cout << num[i] << ' ';
	}
	return 0;
}
