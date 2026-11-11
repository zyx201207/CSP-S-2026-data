#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using LL = long long;

int c, t, x[N], dis[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while(t--){
		int n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) cin >> x[i];
		
		if(d > n / 2){
			cout << "0\n";
			continue;
		}else{
			cout << n - 2 * d + 1 << "\n";
		}
	}
	return 0;
}
