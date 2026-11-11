#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2; /// c1 -> R 车厢; s1 -> R 座位; c2 -> S 车厢; s2 -> S 座位 

bool check1(string seat) {
	if((seat[2] == 'A') || (seat[2] == 'B') || (seat[2] == 'C')) return true;
	return false;
}

bool check2(string seat1, string seat2) {
	if(seat1[2] == 'A' && seat2[2] == 'B') return true;
	if(seat1[2] == 'B' && seat2[2] == 'A') return true;
	if(seat1[2] == 'B' && seat2[2] == 'C') return true;
	if(seat1[2] == 'C' && seat2[2] == 'B') return true;
	if(seat1[2] == 'D' && seat2[2] == 'F') return true;
	if(seat1[2] == 'F' && seat2[2] == 'D') return true;
	return false;
}

int main() {
    (void)freopen("travel.in", "r", stdin);
    (void)freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
    	cout << 1;
    	if((s1[0] == s2[0]) && (s1[1] == s2[1])) {
    		cout << 1;
    		if(check1(s1) == check1(s2)) {
    			cout << 1;
    			if(check2(s1, s2)) {
    				cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
    return 0;
}

