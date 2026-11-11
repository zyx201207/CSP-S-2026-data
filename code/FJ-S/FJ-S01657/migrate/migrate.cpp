#include <bits/stdc++.h>
using namespace std;
int a[10000005];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t; 
	while(t--) {
		int n,d;
		cin >> n >> d;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i]; 
		}
		for (int i = 1; i <= n; i++) {
			if(a[i] + d + 1 == a[i + d + 1]) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

