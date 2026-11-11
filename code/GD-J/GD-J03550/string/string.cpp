#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, sum = 0;
	cin >> n;
	if(n == 1) {
		cout << 0;
	} 
	while(n--) {
		int a;
		cin >> a;
		string s;
		cin >> s;
		sum += a;
		for (int i = 1; i <= n; i++) {
			if (s[i] == s[i + 1]) {
				cout << 0;
				return 0;
			}
		}
	}
	cout << ceil(sum / 2);
} 
