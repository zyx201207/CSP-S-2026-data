#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		long long k;
		cin >> k;
		string h;
		cin >> h;
		for (long long j = 1; j <= k; j++) {
			s += h;
		}
	}
	long long l = s.size();
	string u = s;
	reverse(u.begin(), u.end());
	long long sum = 0;
	for (long long i = 0; i < l / 2; i++) {
		if (s[i] != u[i]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
