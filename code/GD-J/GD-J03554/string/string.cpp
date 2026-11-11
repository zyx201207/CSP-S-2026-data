#include<bits/stdc++.h>
using namespace std;
int n, a[200010];
char c[2000010];
string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	int cnt = 0, tmp;
	for(int i=1; i<=n; i++) {
		cin >> a[i] >> c[i];
		if(c[i] != c[i-1] && i > 1) {
			cnt += 1, tmp = i;
		}
	}
	if(cnt == 0) {
		cout << 0;
		return 0;
	} if(cnt == 1) {
		long long u = 0, v = 0;
		for(int i=1; i<tmp; i++) {
			u += a[i];
		} for(int i=tmp; i<=n; i++) {
			v += a[i];
		}
		long long t = max(u, v) - abs(u-v);
		cout << min(t, (long long)min(u, v));
		return 0;
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=a[i]; j++) {
			s += c[i];
		}
	}
	long long len = s.size(), t = 0;
	for(int i=len/2; i<len; i++) {
		if(s[i] != s[len-i-1]) {
			t++;
		}
	}
	cout << t;
	return 0;
}
