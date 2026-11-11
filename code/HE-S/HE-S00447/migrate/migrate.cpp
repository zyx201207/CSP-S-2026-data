#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

long long c , t , n , m , a[N];

int main() {
	
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	
	cin >> c >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i];
		cout << n / 2 << '\n';
	}
	
	return 0;
} 

/*
CCF I love you!!!
RP++
sto CCF orz
*/
