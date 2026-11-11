#include <bits/stdc++.h>
using namespace std;
string a, a1, b, b1;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> a1 >> b >> b1;
	if (a != b){
		cout << "0000";
	}
	else{
		cout << 1;
		if (a1[0] == b1[0] && a1[1] == b1[1]){
			cout << 1;
			if ((a1[2] - 'C' <= 0) == (b1[2] - 'C' <= 0)){
				cout << 1;
				if (abs(a1[2] - b1[2]) == 1){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout <<"000";
		}
	}
	return 0;
} 
