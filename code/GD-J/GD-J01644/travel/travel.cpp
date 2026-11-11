#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);
	string s1, s2, c1, c2;
	cin >> s1 >> c1 >> s2 >> c2;
	if (s1 == s2){
		cout << 1;
		if (c1 [0] == c2 [0] && c1 [1] == c2 [1]){
			cout << 1;
			if ((c1 [2] <= 'C' && c2 [2] <= 'C') || (c1 [2] >= 'D' && c2 [2] >= 'D')){
				cout << 1;
				if (c1 [2] >= 'D' && c2 [2] >= 'D'){
					cout << 1;
				}
				else {
					if ((c1 [2] == 'A' && c2 [2] == 'C') || (c1 [2] == 'C' && c2 [2] == 'A')){
						cout << 0;
					}
					else {
						cout << 1;
					}
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
