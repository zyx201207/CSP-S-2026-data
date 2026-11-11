#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	
	
	int p1 = (s1[0] - 48) * 10 + s1[1] - 48;
	int p2 = (s2[0] - 48) * 10 + s2[1] - 48;
	
	char ch1 = s1[2];
	char ch2 = s2[2];
	
	if(c1 == c2) {
		cout << "1";
		if(p1 == p2) {
			cout << "1";
			if(ch1 <= 'C' && ch2 <= 'C' || ch1 > 'C' && ch2 > 'C') {
				cout << "1";
				
				if(ch1 + 1 == ch2 || ch2 + 1 == ch1) {
					cout << "1";
				} else {
					cout << "0";
				}
				
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else cout << "0000";
	
	cout << endl;
} 
