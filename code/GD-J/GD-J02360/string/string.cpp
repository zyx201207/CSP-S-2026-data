#include <bits/stdc++.h>
using namespace std;

string s;
long long n;
long long ans;

bool isflag(string k) {
	long long len = k.size() - 1;
	for (long long i = 0; i < len; i++) {
		if (k[i] != k[len - i]) return false;
	}
	return true;
}


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		char c;
		cin >> c;
	    for (long long j = 1; j <= a; j++) {
	    	s += c;
		}
	}
	if (isflag(s)) {
		cout << 0;
		return 0;	
	}
	long long len2 = s.size() - 1;
	for (long long i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[len2 - i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
