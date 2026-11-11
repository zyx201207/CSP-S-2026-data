#include<bits/stdc++.h>
using namespace std;

int c1, c2;
char s1[5], s2[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int pai1 = (s1[0] - '0') * 10 + (s1[1] - '0'), pai2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	char lie1 = s1[2], lie2 = s2[2];
	bool t1 = c1 == c2;
	bool t2 = pai1 == pai2;
	bool t3 = (lie1 >= 'A' && lie1 <= 'C' && lie2 >= 'A' && lie2 <= 'C') || (lie1 >= 'D' && lie1 <= 'F' && lie2 >= 'D' && lie2 <= 'F');
	bool t4 = (lie1 + 1 == lie2 )|| (lie1 - 1 == lie2);
	if(t1) {
		cout << 1;
		if(t2) {
			cout << 1;
			
			if(t3) {
				cout << 1;
				cout << t4;
			}
			else 
				cout << "00";
		}
		else
			cout << "000";
	}
	else 
		cout <<"0000";
	return 0;
}
