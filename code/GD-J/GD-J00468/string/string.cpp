#include<bits/stdc++.h>
using namespace std;
long long n, a[200010];
char c[200010];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >>n;
	for(int i = 1; i <= n; i++) {
		cin >>a[i]; cin >>c[i];
	}
	long long i = 1, j = n, ans = 0;
	while(i < j) {
		long long k = min(a[i], a[j]);
		a[i] -= k; a[j] -= k;
		if(c[i] != c[j]) ans += k;
		if(a[i] == 0) i++;
		if(a[j] == 0) j--;
		if(i >= j) break;
	}
	cout <<ans;
}
