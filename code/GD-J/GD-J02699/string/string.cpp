#include <bits/stdc++.h>
using namespace std;

const int N = 114514;
int n, x, a[N], ans = 0;
char c;

queue<char> q;
stack<char> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c;
	}
	
	if (n == 1) {
		cout << 0;
	} else if (n == 2) {
		cout << min(a[2], a[1]);
	}
	return 0;
}

