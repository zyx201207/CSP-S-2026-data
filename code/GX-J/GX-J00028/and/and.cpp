#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxN = -1e9, n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			maxN = max(a[i]&a[j], maxN);
		}
	}
	cout << maxN;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

