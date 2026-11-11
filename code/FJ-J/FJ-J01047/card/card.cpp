#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, m;
int a[N];
int b[N];
int sum[N];
bool x[N];

int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		b[i] = i + 1;
		for (int j = i + 1; j <= n; j++)
			if (a[i] == a[j]) b[i] = j + 1;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) x[j] = 0;
		int y = i;
		while (y <= n) {
//			cout << y << ' ';
			if (!x[a[y]]) {
				sum[a[y]]++;
				x[a[y]] = 1;
			}
			
			y = b[y];
		}
//		cout << y << endl;
	}
	
	for (int i = 1; i <= m; i++) cout << sum[i] << ' ';
	return 0;
}
