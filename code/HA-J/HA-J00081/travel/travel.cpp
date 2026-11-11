#include <bits/stdc++.h>
using namespace std;

// I PM Testify!!!
// I AP Desultory Signals!!!
// I cai 53.8!!!
// I DXScoreMAX Xaleid◇scopiX!!!
// I AJC Melodiniq!!!
// I AK IOI!!!
// I AK IMO!!! 
// x x xxx
// xxx xx xx xxxxxxx

/*
迷惑行为诱捕器
froepen 
feropen
//freopen
int x1, x0, y0, y1;
*/ 
//``` 
/*
游记：

8:45 才给试题解压密码
9:15 T1过了，小模拟
9:21 开始T2
9:22 IAKIOI
		 打拔大蒜中…… 
9:29 闹麻了，这啥呀 
9:47 不会了，打T3
9:48 秒懂O(NlogNlogMaxA) 
10:10 T3过 
10:14 T3>T2，所以T是负数 
10:32 燃尽了，骗点分，give me 1= plz
10:34 好难
10:35 我要玩Phigros ARCAEA maimaiDX CHUNITHM O.N.G.E.K.I. RYCEAM Milthm Notanote vivid/stasis Paradigm:Reboot ProjectSEKAI:ColorfulStage BanGDream
11:13 T2会了
11:21 又不会了 cout << 0;
12:03 交了 
*/

int Synthesis_tn_shi(char c) {
	if (c <= 'D')
		return c - 'A';
	else
		return 4;
}

int main() {
	string FILENAME = "travel";
	string IFILE = FILENAME + ".in";
	string OFILE = FILENAME + ".out";
	freopen(IFILE.c_str(), "r", stdin);
	freopen(OFILE.c_str(), "w", stdout);
	
	string c1, c2, s1, s2;
	char n1, n2;
//```
	cin >> c1;
	for (int i = 1; i <= 2; i++) {
		char x;
		cin >> x;
		s1 += x;
	}
	cin >> n1;
	
	cin >> c2;
	for (int i = 1; i <= 2; i++) {
		char x;
		cin >> x;
		s2 += x;
	}
	cin >> n2;
	
	if (c1 == c2) {
		cout << 1;
		
		if (s1 == s2) {
			cout << 1;
			
			int x1 = Synthesis_tn_shi(n1), x2 = Synthesis_tn_shi(n2);
			
			if ((x1 <= 2 && x2 <= 2) || (x1 > 2 && x2 > 2)) {
				cout << 1;
				
				if (abs(x1 - x2) == 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0;
				cout << 0;
			}
		} else {
			cout << 0;
			cout << 0;
			cout << 0;
		}
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
	
	cout << endl;
}
