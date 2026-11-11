#include <bits/stdc++.h>
using namespace std;

string side(string a){
	if (a == "A" || a == "B" || a == "C") return "side1";
	return "side2";
}

bool seat_if(string a, string b){
	if (a == "B" || b == "B" || a == "D" || b == "D") return true;
	return false;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	int line1, line2;
	string seat1, seat2;
	cin >> c1 >> s1 >> c2 >> s2;
	line1 = (int)s1[0] + (int)s1[1];
	line2 = (int)s2[0] + (int)s2[1];
	seat1 = s1[2];
	seat2 = s2[2];
	if (c1 == c2){
		if (line1 == line2){
			if (side(seat1) == side(seat2)){
				if (seat_if(seat1, seat2)){
					cout << "1111";
				}else{
					cout << "1110";
				}
			}else{
				cout << "1100";
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
