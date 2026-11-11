#include <iostream>
#include <string>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string cr, sr, cx, sx;
	
	cin >> cr >> sr >> cx >> sx;
	
	int a[4] = {0, 0, 0, 0};
	
	if (cr == cx) {
		a[0] = 1;
		
		if ((sr[0] - '0') * 10 + (sr[1] - '0') == (sx[0] - '0') * 10 + (sx[1] - '0')) {
			a[1] = 1;
			
			if ((sr[2] <= 'C' && sx[2] <= 'C') || (sr[2] > 'C' && sx[2] > 'C')) {
				a[2] = 1;
				
				if (abs(sr[2] - sx[2]) == 1) {
					a[3] = 1;
				}
			}
		}
	}
	
	for (int i = 0; i < 4; ++i) {
		cout << a[i];
	}
	
	return 0;
} 
