#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 2e5 + 10;

int n, a[N], b[N];
char c[N], d[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	fileIO("string");
	
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		b[n - i + 1] = a[i];
		d[n - i + 1] = c[i];
	}
	
	long long ans = 0;
	for(int i = 1, j = 1; i <= n; i ++) {
		while(a[i] > b[j]) {
			if(c[i] != d[j]) ans += b[j];
			a[i] -= b[j];
			j ++;
		}
		if(c[i] != d[j]) ans += a[i];
		b[j] -= a[i];
	}
	cout << ans / 2 << "\n";
} 
