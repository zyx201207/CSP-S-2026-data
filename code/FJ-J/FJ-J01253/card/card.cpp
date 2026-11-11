#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
long long a[N], t[N],s[M];
long long n, m, b = 1, pos = 0, k = 1;
bool check (int x) {
	for (int i = 1; i <= n; i++) {
		if (t[i] == x) return true;
	}
	return false;
}
int find_1 (int x) {
	for (int i = 1; i <= n; i++) {
		if (t[i] == x) {
			return i;
		}
	}
}
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int b = 1; b <= n; b++) {
		k = 1;
		for (int i = b; i <= n; i++) {
			if (check(a[i])) {
				pos = find_1(a[i]);
				for (int j = pos; j <= i; j++) {
					t[j] = 0;
				}
				k = pos;
			}
			t[k] = a[i];
			k++;
		}
		for (int i = 1; i <= n; i++) {
			s[t[i]]++;
		}
		memset(t, 0, sizeof t);
	}

	for (int i = 1; i <= m; i++) {
		cout << s[i] << " ";
	}
	return 0;
}
