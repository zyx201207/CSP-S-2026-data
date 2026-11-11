#include <bits/stdc++.h>
using namespace std;

int a[200005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	int x;
	x = floor(n * 1.0 / 2);
	cout << a[x];
	return 0;
}

