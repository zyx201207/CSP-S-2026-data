#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n = 2e5;
	cout << n << '\n';
	for(int i = 1; i <= n; i++) {
		cout << 1000000000 - n + i << ' ' << char('a' + (i & 1)) << '\n';
	}
    return 0;
}
