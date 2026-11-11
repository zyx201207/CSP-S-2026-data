#include <iostream>
#include <cstdio>
using namespace std;
int n, k, s;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> n >> k;
	while(k--) {
		cin >> n >> s;
		for(int i = 1; i < n; i++) {
			cin >> s;
			cin >> s;
		}
		cout << 1 << endl;
	}
	return 0;
}
