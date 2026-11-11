#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int T,c;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	srand(c);
	while(T--) {
		int n,x;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> x;
		}
		cout << rand() % n << "\n";
	}
	return 0;
}
