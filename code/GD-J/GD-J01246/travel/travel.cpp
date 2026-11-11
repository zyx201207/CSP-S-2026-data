#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check1 (char x, char y) {  //  是否位于过道的同一侧（默认前置条件满足） 
	if ((x == 'A' || x == 'B' || x == 'C') && (y == 'A' || y == 'B' || y == 'C')) {
		return true;
	}
	if ((x == 'D' || x == 'F') && (y == 'D' || y == 'F')) {
		return true;
	}
	return false;
}

bool check2 (char x, char y) {  // 座位是否相邻（默认前置条件满足） 
	if ((x == 'A' && y == 'B') || (x == 'B' && y == 'C') || (x == 'D' && y == 'F')) {
		return true;
	}
	if ((y == 'A' && x == 'B') || (y == 'B' && x == 'C') || (y == 'D' && x == 'F')) {
		return true;
	}
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string t1, k1, t2, k2;
	// R的车厢号、座位号；X的车厢号、座位号
	
	cin >> t1 >> k1 >> t2 >> k2;
	
	bool f1, f2, f3, f4;
	f1 = f2 = f3 = f4 = false;
	
	// 1. 是否在同节车厢 
	if (t1 == t2) f1 = true;
	
	// 2. 是否在同车厢的同排 
	if (f1 && k1[0] == k2[0] && k1[1] == k2[1]) f2 = true; 
	
	// 3. 是否在同车厢的同排，且位于过道的同侧 
	if (f1 && f2 && check1(k1[2], k2[2]))  f3 = true;
	
	// 4. 座位是否相邻 
	if (f1 && f2 && f3 && check2(k1[2], k2[2]))  f4 = true;
	
	
	cout << f1 << f2 << f3 << f4;
	return 0;
}

/*
100
*/
