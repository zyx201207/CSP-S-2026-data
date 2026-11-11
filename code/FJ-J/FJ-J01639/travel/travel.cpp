#include<bits/stdc++.h>
using namespace std;
int R1, X1;
string R2, X2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> R1 >> R2 >> X1 >> X2;
	if (R1 == X1){
		cout << 1;
		if (R2[0] == X2[0] && R2[1] == X2[1]){
			cout << 1;
			if ((R2[2] == 'D' && X2[2] == 'E') || (R2[2] == 'E' && X2[2] == 'D') || ((R2[2] != 'D' && R2[2] != 'E') && (X2[2] != 'D' && X2[2] != 'E'))){
				cout << 1;
				if (R2[2] + 1 == X2[2] || R2[2] - 1 == X2[2]){
					cout << 1;
				}
				else {
					cout << "0";
				}
			}
			else {
				cout << "00";
			}
		}
		else {
			cout << "000";
		}
	}
	else {
		cout << "0000";
	}
	return 0;
}
