#include <bits/stdc++.h>
using namespace std;

/*
(至少我认为) 100 分 
*/

string c1, s1, c2, s2;

int CtoDig(string s) {
	int res;
	if (s[0] == '0') res = s[1] - '0';
	else res = (s[0] - '0')*10 + (s[1] - '0');
	
	return res;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	int ic1, ic2;
	
	//车厢字符串转数字
	ic1 = CtoDig(c1);
	ic2 = CtoDig(c2);
	
	cout << (ic1 == ic2);
	
	if (ic1 != ic2) {
		cout << "000";
		return 0;
	}
	
	string ds1 = "99", ds2 = "99";
	int ids1, ids2;	// 数字化的座位号 
	char cs1, cs2;	// 座位字母 
	
	// 分离座位号
	ds1[0] = s1[0]; ds1[1] = s1[1];
	ds2[0] = s2[0]; ds2[1] = s2[1];
	
	ids1 = CtoDig(ds1);
	ids2 = CtoDig(ds2);
	cs1 = s1[2], cs2 = s2[2];
	
	cout << (ids1 == ids2); // 是否在同一排
	if (ids1 != ids2) {
		cout << "00";
		return 0; 
	}
	
	// 是否同一侧 & 是否相邻
	if ( (cs1 == 'D' && cs2 == 'F') || (cs1 == 'F' && cs2 == 'D')) {
		cout << "11";
		return 0;
	} else if ( (min(cs1, cs2) >= 'A') && (max(cs1, cs2) <= 'C') ) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	if (abs(cs1 - cs2) == 1 && (max(cs1, cs2) <= 'C' ) ) {
		cout << 1; 
	} else cout << 0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

