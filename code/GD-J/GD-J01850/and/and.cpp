#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i=0;i<n;i++) {
		cin >> a[i];
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (a[j] > a[i]) {
				swap(a[j], a[i]);
			}
		} 
	}
	cout << a[m-1] << endl;
}
