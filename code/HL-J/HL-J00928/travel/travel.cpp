#include <bits/stdc++.h> 

using namespace std;

string c1, c2, c3, c4;

int main() {
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin  >>c1 >> c2 >> c3 >> c4;
	
	if (c1 == c3) {
		cout << 1;
		if (c2[0] == c4[0] && c2[1] == c4[1]) {
		cout << 1;
		if(c2[2] == 'C') {
			if(c4[2] == 'D') {
				cout << 0;
			} else {
				cout << 1;
			}
		} else if(c2[2] == 'D') {
			if(c4[2] == 'C') {
				cout << 0;
			} else {
				cout << 1;
			}
		}
	} else {
		cout <<0;
	}
	
	
	
	
	if(c2[2] == 'A') {
		if(c4[2] == 'B') {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if(c2[2] == 'B') {
		if(c4[2] == 'C') {
			cout << 1;
		} else {
			cout << 0;
		}
	}  else if(c2[2] == 'C') {
		if(c4[2] == 'B') {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if(c2[2] == 'B') {
		if(c4[2] == 'A') {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if(c2[2] == 'D') {
		if(c4[2] == 'F') {
			cout << 1;
		} else {
			cout << 0;
		}
	}  else if(c2[2] == 'F') {
		if(c4[2] == 'D') {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
	
	 

	
	
	return 0;
}