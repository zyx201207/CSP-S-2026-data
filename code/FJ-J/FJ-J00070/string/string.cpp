#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

//#define DEBUG
#ifdef DEBUG
#define debug(fmt,...) printf(fmt,##__VA_ARGS__)
#else
#define debug(fmt,...)
#endif

/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000 a
1000 a
1000 a
1000 b
1000 b
1000 b

5
2 a
2 b
3 c
1 d
4 e

6
1 a
2 a
1 b
2 c
1 a
2 c


*/

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin >> n;
	for (int i= 0;i < n;i++) {
		int a;
		char c;
		cin >> a >> c;
		for (int j = 0;j < a;j++) {
			s += c;
		}
	}
	ll l = 0;
	ll r = s.length() - 1;
	ll ans = 0;
	while (l < r) {
		if (s[l] != s[r]) {
			ans++;
		}
		l++;
		r--;
	}
	cout << ans;
	return 0;
}
