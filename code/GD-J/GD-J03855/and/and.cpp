#include <bits/stdc++.h>
using namespace std;

int a[200005];

bool cmp(int a, int b) {
	return a > b;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n;
	cin >> n;
	int m;
	cin >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	/*for(int i = 0; i < n; i++) {
		cout << a[i];
	}*/
	int ans = a[0];
	for(int i = 0; i < m; i++) {
		if(__builtin_popcount(a[i]) == 1) {
			i++;
		}
		ans &= a[i];
		cout << a[i] << " ";
		//cout << ans;
	}
	//cout << ans;
	return 0;
}
