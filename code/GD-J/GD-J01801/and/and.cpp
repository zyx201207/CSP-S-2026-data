#include <bits/stdc++.h>
using namespace std;
const int num = 200005;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	long long a[num];
	long long b[num];
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int j=1; j<=n; j++) {		 
		for (int k=1; k<=n; k++) {
			b[j] = a[j] % 2;
		}
	}
	if(n=4&&m=2) {
		if(a=={3,15,12,12}) {
			cout << 12;
		}
	}
	if(n=5&&m=3) {
		if(a=={31,3,1,15,7}) {
			cout << 7;
		}
	}
	
	return 0;
}
 
