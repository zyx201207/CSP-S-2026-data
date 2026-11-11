#include <bits/stdc++.h>
using namespace std;
int a[2000005];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		long long n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(a[2] - a[1] != a[3] - a[2]){
			cout << (n - 2) * (n - 1) / 2 << endl;
		}else{
			int gc = a[2] - a[1];
			d /= gc;
			d += 2;
			cout << n - d + 1 << endl;
		}
	}
	return 0;
}
