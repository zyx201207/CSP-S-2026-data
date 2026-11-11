#include<bits/stdc++.h>
using namespace std;

int c1, c2, s1, s2;
char p1, p2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> p1 >> c2 >> s2 >> p2;
	if(c1 == c2) {
		cout << 1;
		if(s1 == s2){
			cout << 1;
			if(((p1 >= 'A' && p1 <= 'C') && (p2 >= 'A' && p2 <= 'C')) || ((p1 == 'D'&& p2 == 'F') || (p2 == 'D'&& p1 == 'F'))){
				cout << 1;
				if(abs(p1 - p2) == 1) cout << 1;
				else {
					cout << 0;
					return 0;
				}
			}
			else {
				cout << "00";
				return 0;
			}
		}
		else {
			cout << "000";
			return 0;
		}
	}
	else {
		cout << "0000";
		return 0;
	}
	return 0;
}
