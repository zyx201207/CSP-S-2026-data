#include <bits/stdc++.h>

using namespace std;
const int MAX = 5e5 + 10;
int a[MAX], c[MAX];
bool b[MAX];
int n, m;
void p(int cnt) {
	for (int i = cnt; i <= n; i++) {
		for (int j = cnt; j <= i; j++) {
			if (a[i] == a[j]) {
				for (int k = j; k <= i; k++) {
					b[k] == 0;
				}
			}
		}
	}
	for (int i = cnt; i <= n; i++) {
		if(b[i]) c[a[i]]++;
	}
}
void g() {
	for (int i = 1; i <= n; i++) {
		b[i] = 1;
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		p(i);
		g();
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
	return 0;
}

