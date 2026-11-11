#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 5;
int n;
ll m, c[MAXN], d[MAXN], e[MAXN], ans;
bool fl = 1, flw = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] != i) fl = 0;
	}
	
	sort(c + 1, c + n + 1);
	
	for (int i = 3; i <= n; i++) {
		if (c[i] - c[i - 1] != c[i - 1] - c[i - 2]) flw = 0;
	}
	
	if (fl) {
		for (int i = n; i >= 1; i--) {
			if (((c[i] - 1) * c[i]) / 2 <= m) {
				cout << i << "\n";
				return 0;
			}
		}
	} else if(flw) {
		ll gp = c[2] - c[1];
		for (int i = n; i >= 1; i--) {
			if (i % 2 == 0) {
				if ((c[i] - c[1] + c[i] - c[i - 1]) * (i / 2 - 1) + (c[i] - c[1] + c[i] - c[i - 1]) / 2 <= m) {
					cout << i << "\n";
					return 0;
				}
			} else {
				if ((c[i] - c[1] + c[i] - c[i - 1]) * (i / 2 - 1) <= m) {
					cout << i << "\n";
					return 0;
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		d[i] = c[i] - c[i - 1];
		e[i] = d[i] * (i - 1) + e[i - 1];
	}
	
	int id = lower_bound(e + 1, e + n + 1, m) - e;
	while (e[id] == e[id + 1]) {
		id++;
	}
	
	if (e[id] > m) {
		cout << id - 1 << "\n";
	} else {
		cout << id;
	}
	return 0;
} 
