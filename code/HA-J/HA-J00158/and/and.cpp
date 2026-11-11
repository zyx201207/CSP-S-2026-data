#include<bits/stdc++.h>
using namespace std;

int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[200010] = {};
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	int mx = 0;
	if (m == 2) {
		for (int i = 1;i < n;i++) {
			for (int j = 2;j <= n;j++) {
				if (a[i] | a[j] > mx) mx = a[i] | a[j];
			}
		}
	}
	else {
		for (int i = 1;i < n - 1;i++) {
			for (int j = 2;j < n;j++) {
				for (int k = 3;k <= n;k++) {
					if (a[i] | a[j] | a[k] > mx) mx =  a[i] | a[j] | a[k];
				}
			}
		}
	}
	cout << mx;
	return 0;
}
