#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int c , t;
	cin >> c >> t;
	while(t--) {
		int n , k , u , v;
		cin >> n >> k >> u >> v;
		n--;
		while(n--) {
			cin >> u >> v;
		}
		cout << n << endl;
	}
	return 0;
}
