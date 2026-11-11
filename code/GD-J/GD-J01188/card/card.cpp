#include<bits/stdc++.h>

using namespace std;
int n, m;
const int M = 1000000;
int a[M],c[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<int> b(m + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int j = 1; j <= n; ++j) {
	for(int i = j; i <= n; ++i) {
		if(b[a[i]] == 0) {
			b[a[i]] = 1;
		}else {
			for(int h = 1; h <= m; h ++) {
	b[h] = 0;
}
			b[a[i]] = 1;
		}
	}
	for(int i = 1; i <= m; ++i) {
		c[i] += b[i]; 
		b[i] = 0;
	}
}
for(int i = 1; i <= m; i ++) {
	cout << c[i] << ' ';
}
	return 0;
} 
