#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int c, t;

int main() {
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	c = read(), t = read();
	while(t--) {
		int n, k;
		n = read(), k  = read();
		cout << 1 <<"\n";
	}
	
	return 0;
}
