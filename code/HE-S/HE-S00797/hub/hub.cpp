#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int N = 2e6 + 5;
int c, t, n, k;

signed main() {
	freopen("hub.in ", "r", stdin);
	freopen("hub.out ", "w", stdout);
	c = rd();
	t = rd();
	while(t --) {
		n = rd();
		k = rd();
		cout << n - 1 << '\n';
	}
	return 0;
}
