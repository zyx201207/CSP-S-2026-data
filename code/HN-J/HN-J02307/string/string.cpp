#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e7 + 50;

char a[MAXN];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, flag = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int s;
		char c;
		cin >> s >> c;
		for(int j = 1; j <= s; j++) {
			flag++;
			a[flag] = c;
		} 
	}
	int ans = 0;
	for(int i = 1; i <= flag; i++) {
		if(a[i] != a[flag + 1 - i]) ans++;
	}
	cout << ans / 2;
	return 0;
} 
