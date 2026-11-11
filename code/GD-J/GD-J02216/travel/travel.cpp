#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,n1,n2;
	cin >> n1 >> s1 >> n2 >> s2;
	if (n1[0] == n2[0] && n1[1] == n2[1]) { //判断是否在同一车厢 
		cout << "1";
		if (s1[1] == s2[1] && s1[0] == s2[0])  { //判断是否在同一排 
			cout << "1";
			if (s1[2] == 'A') { //判断是否在统一侧 
				if (s2[2] == 'B' || s2[2] == 'C') { //判断是否相邻 
					cout << "1";
					if (s2[2] == 'B') cout << "1";
					else cout << "0";
				}
				else cout << "00";
			}
			else if (s1[2] == 'B') {
				if (s2[2] == 'A' || s2[2] == 'C') { //判断是否相邻 
					cout << "11";
				}
				else cout << "00";
			}
			else if (s1[2] == 'C') {
				if (s2[2] == 'A' || s2[2] == 'B') { //判断是否相邻 
					cout << "1";
					if (s2[2] == 'B') cout << "1";
					else cout << "0";
				}
				else cout << "00";
			}
			else if (s1[2] == 'D') {
				if (s2[2] == 'E') { //判断是否相邻 
					cout << "11";
				}
				else cout << "00";
			}
			else if (s1[2] == 'E') {
				if (s2[2] == 'D') { //判断是否相邻 
					cout << "11";
				}
				else cout << "00";
			}
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
