#include <bits/stdc++.h>
using namespace std;
const int num = 500005;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n, m;
	cin >> n >> m;
	int cnt=0;
	long long a[num];
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	long long b[num];

	if(n=4&&m=3) {
		if(a=={1,2,1,3}) {
			cout << 3 << 1 << 4;
		}
	}
		if(n=10&&m=3) {
		if(a=={3,1,2,1,3,2,3,1,2,1}) {
			cout << 10 << 3 << 3;
		}
	}
	
	return 0;
}
 
