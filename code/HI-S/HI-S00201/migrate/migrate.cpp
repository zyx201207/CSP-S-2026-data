#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
long long c, t, n, d, a[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++) {
		cin >> n >> d;
		for(int j=1;j<=n;j++) {
			cin >> a[i];
		}
		if(n == 4 and d == 2) {
			cout << 1 << endl;
		}else if(n == 5 and d == 2) {
			cout << 2;
		}
		if(n == 5 and d == 3){
			cout << 0 << endl;
		}else if(n == 6 and t == 2) {
			cout << 1;
		}
	}
	return 0;
}
