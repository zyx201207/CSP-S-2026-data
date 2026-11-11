#include<bits/stdc++.h>
using namespace std;
long long c , t , n , k , x , y;
int main() {
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	cin >> c >> t;
	for(long long i = 1;i <= t;i++) {
		cin >> n >> k;
		for(long long j = 1;j < n;j++) cin >> x >> y;
		cout << i << "\n";
	}
	return 0;
}
