#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n, a, ans = 0;
	char c;
	string s = "";
	cin >> n;
	for(long long i = 1; i <= n; ++i) {
		cin >> a;
		cin >> c;
		for(long long i = 1; i <= a; ++i) {
			s += c;
		}
	}
	long long len = s.size();
	if(len % 2 == 0) {
		long long l = len / 2 - 1;
		long long r = l + 1;
		while(l >= 0 && r <= len) {
			if(s[l] != s[r]) {
				ans++;
			}
			l--;
			r++;
		}
	}
	else{
		long long l = len / 2 - 1;
		long long r = l + 2;
		while(l >= 0 && r <= len) {
			if(s[l] != s[r]) {
				ans++;
			}
			l--;
			r++;
		}
	}
	cout << ans;
	return 0;
}
