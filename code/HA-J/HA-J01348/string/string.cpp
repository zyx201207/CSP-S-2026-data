#include <bits/stdc++.h>

using namespace std;
const int MAX = 2e5 + 10;
int a[MAX];
char c[MAX], s[MAX];
int n;
bool check() {
	for (int i = 1, j = n; i <= n; i++, j--) {
		if (s[i] != s[j]) return false;
	}
	return true;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i] >> c[i];
	}
	long long MIN = 1e9;
	for (int i = 1; i <= n; i++) {
		
	}
	return 0;
} 
