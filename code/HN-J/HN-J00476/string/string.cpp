#include <bits/stdc++.h>
using namespace std;

long long a[200005];
char c[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i] >> c[i];
	}
	cout << ceil(n * 1.0 / 2);
	return 0;
}
