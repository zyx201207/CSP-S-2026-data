#include <bits/stdc++.h>
using namespace std;
int c, t;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(t--){
		int n, w;
		cin >> n >> w;
		int a[n + 10];
		for(int i = 1; i <= n; ++i) cin >> a[i];
		if(a[n] - a[1] <= w){cout << "0\n"; continue;}
		int x = a[2] - a[1], ok = 1;
		for(int i = 3; i <= n; ++i){
			if(a[i] - a[i - 1] != x) {ok = 0; break;}
		}
		if(ok){
			int k = w / x;
			if(k != 2){cout << "0\n"; continue;}
			cout << n - 3 << "\n";
			continue;
		}
		cout << "0\n";
	}
	return 0;
}


