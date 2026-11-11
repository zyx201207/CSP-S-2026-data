#include<bits/stdc++.h>

using namespace std;

string ca_train_r, ca_train_x, ca_sit_r, ca_sit_x;

bool yes1(string s1, string s2) {
	string sub1 = s1.substr(0, 2);
	string sub2 = s2.substr(0, 2);
	if(sub1 == sub2) return true;
	else return false;
}

bool yes2(string s1, string s2) {
	int n1 = s1[2] - 'A';
	int n2 = s2[2] - 'A';
	if((n1 <= 2 && n2 <= 2) || (n1 > 2 && n2 > 2)) return true;
	else return false;
}

bool yes3(string s1, string s2) {
	int x1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	int y1 = s1[2] - 'A';
	int x2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	int y2 = s2[2] - 'A';
	if(abs(x1 - x2) == 1 || abs(y1 - y2) == 1) return true;
	else if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) {
		if(abs(x1 - x2) == 1) return true;
	}
	else return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> ca_train_r >> ca_sit_r >> ca_train_x >> ca_sit_x;
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	if(ca_train_r == ca_train_x) {
		a1 = 1;
		if(yes1(ca_train_r, ca_train_x)) {
			a2 = 1;
			if(yes2(ca_sit_r, ca_sit_x)) {
				a3 = 1;
				if(yes3(ca_sit_r, ca_sit_x)) {
					a4 = 1;
				}
			}
		}
	}
	
	cout << a1 << a2 << a3 << a4;
	
	return 0;
}
