#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n = 5e5, m = 3e5;
	cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i++) {
		cout << min(m, i) << ' ';
	}
    return 0;
}
