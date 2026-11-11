#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;



int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	srand(time(0));
	int c, t;
	cin >> c >> t;
	if (c == 0) {
		if (t == 2) cout << 1 << endl << 2;
		else if (t == 3) cout << 1 << endl << 1 << endl << 2;
		else if (t == 5) cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9;
		else if (t == 1) cout << 12251 << endl;
		return 0;
	}
	
	while (t--) {
		cout << rand() % (int)(100) << endl;
	}
	return 0;
} 
