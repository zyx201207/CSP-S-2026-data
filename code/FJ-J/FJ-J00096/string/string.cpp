#include <bits/stdc++.h>
using namespace std;
int n, t, sum;
char c[1000005];
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout);
	cin >>n;
	for (int i = 1; i<=n; i++) {
		int a;
		char b;
		cin >> a >> b;
		for (int j = t; j < a + t; j++) c[j] = b;
		t += a;
	}
	for (int i = 0; i < t/2; i++) {
		if (c[i] != c[t-i-1]) sum ++; 
	}
	cout << sum;
	return 0;
}
