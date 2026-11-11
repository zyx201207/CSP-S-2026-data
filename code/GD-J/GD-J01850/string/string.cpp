#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string str;
	int a;
	char b;
	for (int i=0;i<n;i++) {
		cin >> a >> b;
		for (int j=0;j<a;j++) {
			str += b;
		}
	}
	long long ans = 0;
	for (long long i=0;i<str.size();i++) {
		if (str[i] != str[str.size()-i-1]) {
			ans++;
		}
		if (i >= str.size() - i - 1) {
			break;
		}
	}
	cout << ans - 1 << endl;
}
