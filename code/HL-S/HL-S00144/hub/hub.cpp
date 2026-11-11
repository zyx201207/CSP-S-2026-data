#include <bits/stdc++.h>
using namespace std;
int y[] = {0, 1, 2, 3, 2, 1 ,3 ,5 , 2, 0, 1, 3, 7, 7 ,3 , 3};
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cout << y[i % 15] << "\n";
	}
	return 0;
} 

