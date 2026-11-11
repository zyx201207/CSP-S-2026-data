#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n = 2e5, m = 1e5;
	cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i++) {
		cout << (1 << 30) - i << ' ';
	}
    return 0;
}
