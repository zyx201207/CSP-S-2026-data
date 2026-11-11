#include <bits/stdc++.h>

#define FOR(i, j, k) for(int i = j;i <= k;++i)
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

int x, y;
string c1, c2, s1, s2;

inline int convert(char c) {
	switch(c) {
		case 'A': return 0;
		case 'B': return 1;
		case 'C': return 2;
		case 'D': return 4;
		case 'F': return 5;
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000";
		return 0;
	} else {
		cout << "1";
		if(s1[0] != s2[0]) cout << "000";
		else if(s1[1] != s2[1]) cout << "000";
		else {
			cout << "1";
			x = convert(s1[2]), y = convert(s2[2]);
			if(!((x <= 2 && y <= 2) || (x >= 4 && y >= 4))) cout << "00";
			else {
				cout << "1";
				if(max(x, y) - min(x, y) == 1) cout << "1";
				else cout << "0";
			}
		}
	}
	return 0;
}
/*
E:\GD-J04274\travel>fc travel.out travel1.ans
正在比较文件 travel.out 和 TRAVEL1.ANS
FC: 找不到差异


E:\GD-J04274\travel>travel.exe

E:\GD-J04274\travel>fc travel.out travel2.ans
正在比较文件 travel.out 和 TRAVEL2.ANS
FC: 找不到差异


E:\GD-J04274\travel>travel.exe

E:\GD-J04274\travel>fc travel.out travel3.ans
正在比较文件 travel.out 和 TRAVEL3.ANS
FC: 找不到差异


E:\GD-J04274\travel>travel.exe

E:\GD-J04274\travel>fc travel.out travel4.ans
正在比较文件 travel.out 和 TRAVEL4.ANS
FC: 找不到差异


E:\GD-J04274\travel>travel.exe

E:\GD-J04274\travel>fc travel.out travel5.ans
正在比较文件 travel.out 和 TRAVEL5.ANS
FC: 找不到差异

08:54 AC
*/
