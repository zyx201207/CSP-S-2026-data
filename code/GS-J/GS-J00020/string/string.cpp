#include <bits/stdc++.h>
using namespace std;

long long n, a, tail = 0, k = 0, ans = 0, ok = 1;
char c, s[1000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> c;
		int j;
		for(j = k; j < k + a; j++) s[j] = c;
		k = j;
	}
	
	cout << '0';
	return 0;
}
