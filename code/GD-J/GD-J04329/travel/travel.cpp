#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2; //输入数据 
	
	//判断两张车票对应的座位是否在同一节车厢
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	//判断两张车票对应的座位是否在同一节车厢的同一排
	if (c1 == c2) {
		if ( (s1[0] == s2[0]) && (s1[1] == s2[1]) ) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	
	//判断两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
	bool a = ( ( (s1[2] == 'A') || (s1[2] == 'B') || (s1[2] == 'C') ) && ( (s2[2] == 'A') || (s2[2] == 'B') || (s2[2] == 'C') ) ) ;
	bool b = ( ( (s1[2] == 'D') || (s1[2] == 'E') ) && ( (s2[2] == 'D') || (s2[2] == 'E') ) );
	bool ans = a || b;
	if (c1 == c2) {
		if ( (s1[0] == s2[0]) && (s1[1] == s2[1]) ) {
			cout << ans;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	
	//判断两张车票对应的座位是否相邻
	int x = s1[2] - s2[2];
	if (c1 == c2) {
		if ( (s1[0] == s2[0]) && (s1[1] == s2[1]) ) {
			if (ans) {
				if (b) {
					cout << 1;
				} else if ( abs(x) ) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0; 
			}
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	return 0;
} 
