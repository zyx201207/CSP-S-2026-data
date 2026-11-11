#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(m == 1) {
		cout << ceil(n / 2);
		return 0;
	}
	if(n == 1) {
		for(int i = 1; i <= m; i++) {
			if(a[1] == i) cout << a[1] < " ";
			else cout << "0 ";
		}
		return 0;
	}
	if(n == 2) {
		if(a[1] == a[2]) {
			if(a[1] == 1) cout << "1 0";
			else cout << "0 1";
			return 0;
		}
		else{
			cout << a[1] << " " << a[2];
		}
		return 0;
	}
	return 0;
}
