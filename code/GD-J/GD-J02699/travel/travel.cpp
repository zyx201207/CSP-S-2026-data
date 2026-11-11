#include <bits/stdc++.h>
using namespace std;

int p1, p2;
string s1, s2;

struct seat {
    int num;
    char c;
};

seat seat1, seat2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> p1 >> s1 >> p2 >> s2;
    
    if (seat1.c > seat2.c)
    	swap(seat1, seat2);

    seat1.num = s1[0] * 10 + s1[1];
    seat1.c = s1[2];
    seat2.num = s2[0] * 10 + s2[1];
    seat2.c = s2[2];

    if (p1 != p2) {
        cout << "0000" << "\n";
        return 0;
    } else {
        cout << 1;
    }

    if (seat1.num != seat2.num) {
    	cout << "000" << "\n";
    	return 0;
	} else {
		cout << 1;
	}
	
	if (seat1.c == 'D') {
		cout << "11" << "\n";
		return 0;
	} else if (seat2.c <= 'C') {
		cout << 1;
	} else if (seat1.c == 'C'){
		cout << 0;
	}
	
	if (abs(seat1.c - seat2.c) == 1 && seat2.c != 'D')
		cout << 1;
	else
		cout << 0;
    return 0;
}

