#include<bits/stdc++.h>
using namespace std;
string ans;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string r1, r2, x1, x2;
	cin >> r1 >> r2 >> x1 >> x2;
	if(r1 == x1) {
		if(r2[0] == x2[0] && r2[1] == x2[1]) {
			if((r2[2] <= 'C' && x2[2] <= 'C') || (r2[2] >= 'D' && x2[2] >= 'D')) {
				if(r2[2] >= 'D' && x2[2] >= 'D') {
					cout << "1111";
					return 0;
				}
				else if(r2[2] <= 'C' && x2[2] <= 'C') {
					if((r2[2] == 'C' && x2[2] == 'A') || (r2[2] == 'A' && x2[2] == 'C')) {
						cout << "1110";
						return 0;
					}
					else {
						cout << "1111";
						return 0;
					}
				}
				else {
					cout << "1110";
					return 0;
				}
			}
			else {
				cout << "1100";
				return 0; 
			}
		}
		else {
			cout << "1000";
			return 0;
		}
	}
	else {
		cout << "0000";
		return 0;
	}
	return 0;
}
