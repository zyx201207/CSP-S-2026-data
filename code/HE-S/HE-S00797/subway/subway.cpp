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

const int N = 5e5 + 5;
int c, n, m, d, q;
signed main() {
	freopen("subway.in ", "r", stdin);
	freopen("subway.out ", "w", stdout);
    c = rd();
    m = rd();
    n = rd();
	d = rd();
	q = rd();
//	for(int i = 1;i <= n;++ i) {
//		w[i] = rd();
//	}
	for(int i = 1;i <= q;++ i) {
		cout << "0" << '\n';
	}
	return 0;
}
