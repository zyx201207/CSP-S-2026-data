#include<bits/stdc++.h>
using namespace std;
char seat[7][6];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> seat[1][1] >> seat[1][2];
	cin >> seat[2][1] >> seat[2][2] >> seat[2][3];
	cin >> seat[3][1] >> seat[3][2];
	cin >> seat[4][1] >> seat[4][2] >> seat[4][3];
	if(seat[1][1] == seat[3][1] && seat[1][2] == seat[3][2]) {
		cout << 1;
		if(seat[2][1] == seat[4][1] && seat[2][2] == seat[4][2]) {
			cout << 1;
			int a = seat[2][3] - 'A' + 1;
			int b = seat[4][3] - 'A' + 1;
			if((a <= 3 && b <= 3) || (a >= 4 && b >= 4)) {
				cout << 1;
				if(abs(a - b) == 1) {
					cout << 1; 
				}
				else cout << 0;
			}
			else {
				cout << 0 << 0;
			}
		}
		else {
			cout << 0 << 0 << 0;
		}
	}else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}
