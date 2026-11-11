#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string c1, s1, c2, s2;
bool flag = false;  // 是否在同一节车厢
bool flag2 = false;  // 是否在同一节车厢的同一排
bool flag3 = false;  // 是否在同一节车厢的同一排，且位于过道的同一侧
bool flag4 = false;  // 是否相邻
int main(){
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		// 是否在同一节车厢
		flag = true; 
	}
	if (flag && (s1[0] + s1[1] == s2[0] + s2[1])){
		// 是否在同一节车厢的同一排
		flag2 = true;
	}
	if (flag && flag2 && (((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'A' && s2[2] <= 'C')) || ((s1[2] >= 'D' && s1[2] <= 'F') && (s2[2] >= 'D' && s2[2] <= 'F')))){
		// 是否在同一节车厢的同一排，且位于过道的同一侧
		flag3 = true;
	}
	if ((int(abs(s1[2] - s2[2])) == 1) && flag3){
		// 是否相邻
		flag4 = true;
	}
	cout << flag << flag2 << flag3 << flag4;
	//cout << endl << s1[2] << ' ' << s2[2] << endl << int(abs(s1[2] - s2[2]));
	return 0;
}
