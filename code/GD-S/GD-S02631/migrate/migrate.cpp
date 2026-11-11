#include<iostream>
using namespace std;
const int N = 2e6 + 5;
int a[N];
int c, t;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		long long n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		if(d < a[3] - a[2]) cout << 0 << '\n';
		else cout << n - 3 << '\n';
	}
	return 0;
}

