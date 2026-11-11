#include <iostream>
#include <algorithm>
using namespace std;

string c1, s1, c2, s2;

bool check1() {
	return c1 == c2;
}

bool check2() {
	string sub1 = s1.substr(0, 2);
	string sub2 = s2.substr(0, 2);
	
	return check1() && sub1 == sub2;
}

bool check3() {
	int a1 = s1[2] - 'A', a2 = s2[2] - 'A';
	return check2() && ((a1 <= 2 && a2 <= 2) || (a1 >= 3 && a2 >= 3));
} 

bool check4() {
	int a1 = s1[2] - 'A', a2 = s2[2] - 'A';
	if (a1 < a2) swap(a1, a2);
	return check3() && a1 - a2 == 1;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c1 >> s1;
	cin >> c2 >> s2;
	
	if (check1()) {
		cout << 1; 
		if (check2()) {
			cout << 1;
			if (check3()) {
				cout << 1;
				
				if (check4()) cout << 1;
				else if (!check4()) cout << 0;
			} 
			else if (!check3()) {
				cout << "00";
			}
		} 
		else if (!check2()) {
			cout << "000";
		}
	} 
	else if (!check1()) {
		cout << "0000";
	}
	
	return 0;
}
