#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, cnt;
	cin >> n;
	int a[n];
	char c[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	string s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			s += c[i];
		}
	}
	int flag = 1;
	for (int i = 0 ;i < s.size(); i++) {
		if (s[i] != s[n - i - 1]) flag = 0;
	}
	if (flag) {
		cout << 0;
		return 0;
	}
	if (a[0] > a[n - 1]) {
		cout << a[0];	
	}else if (a[0] == a[n - 1]) {
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != s[0]) {
				cout << i;
				break;
			}
		}
	} 
	else cout << a[n - 1];
	return 0;
}
