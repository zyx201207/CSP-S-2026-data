#include <bits/stdc++.h>
using namespace std;
long long n, a;
char c;
string hw;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> c;
		for (int j = 0; j < a; j++) hw += c;
	}
	long long l = hw.size(), k = 0;
	for (int i = 0; i < l / 2 + 1; i++) if (hw[i] != hw[l - 1 - i]) k++;
	cout << k;
	return 0;
}

