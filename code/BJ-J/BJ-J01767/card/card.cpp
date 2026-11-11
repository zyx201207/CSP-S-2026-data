#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[2000005];
map<ll, ll> mp;
int vc[2000005];
int ss=0;
int my_find(int x) {
	for (int i = 1; i <= ss; i++) {
		if (x == vc[i]) return i;
	}
	return -1;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	bool flag = false;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1 && a[i] < a[i-1]) {
			flag = true;
		}
	}
	if (!flag) {
		for (int i = 1; i <= n; i++) {
			if (a[i] != a[i+1]) {
				cout << i << " ";
			}
		}
		cout << endl;
	} else {
		for (int i = 1; i <= n; i++) {
			ss=0;
			for (int j = i; j <= n; j++) {
				int x = my_find(a[j]);
				if (x != -1) {
					int size = ss;
					for (int i= 1; i <= size-x+1; i++) {
						ss--;
					}
				}
				
				ss++;
				vc[ss]=a[j];
			}
			for (int i = 1; i <= ss; i++) {
				mp[vc[i]]++;
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << mp[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
