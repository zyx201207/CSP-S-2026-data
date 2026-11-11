#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m;
int tmz[35]; 
int tms[35];
bool g[N][35];
int a[N];
bool v[N];

void csh () {
	for (int i = 0; i <= 30; i++) tms[i] = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i]) continue;
		int x = a[i], ji = 0;
		while (x) {
			if (x % 2 == 1) tms[ji]++;
			ji++;
			x /= 2;
		}
	}
}

int main () {
	freopen ("add.in", "r", stdin);
	freopen ("add.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	tmz[0] = 1;
	for (int i = 1; i <= 30; i++) tmz[i] = tmz[i - 1] * 2;
	for (int i = 1; i <= n; i++) {
		int x = a[i], ji = 0;
		while (x) {
			if (x % 2 == 1) g[i][ji] = 1;
			ji++;
			x /= 2;
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= 30; j++) {
//			cout << g[i][j] << ' ';
//		}
//		cout << endl;
//	}
	
	csh();
	
	int sum = 0;
	for (int i = 30; i >= 0; i--) {
		if (tms[i] >= m) {
			for (int j = 1; j <= n; j++) v[j] = (!g[j][i]) || v[j];
			sum += tmz[i];
			csh(); 
		}
	}
	
	cout << sum;
	return 0;
}
