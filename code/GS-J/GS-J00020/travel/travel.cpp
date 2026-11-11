#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int a, c;
	string b, d;
	cin >> a >> b >> c >> d;
	
	if (a == c) {
		cout << "1";
		
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << "1";
			
			if (('A' <= b[2] <= 'C' && 'A' <= d[2] <= 'C') || ('D' <= b[2] <= 'F' && 'D' <= d[2] <= 'F')) {
				cout << "1";
				
				if ((abs(b[2] - d[2]) == 1) || (b[2] == 'F' && d[2] == 'D') || (b[2] == 'D' && d[2] == 'F')) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	
	return 0;
}
