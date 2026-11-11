#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 1;

string c1, c2, s1, s2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << 1;
		int h1 = (s1[0] - '0') * 10 + (s1[1] - '0');
		int h2 = (s2[0] - '0') * 10 + (s2[1] - '0');
		if(h1 == h2) {
			cout << 1;
			int l1 = s1[2] - 'A';
			int l2 = s2[2] - 'A';
			if((l1 <= 2 && l2 <= 2) || (l1 > 2 && l2 > 2)) {
				cout << 1;
				if((l1 + 1 == l2 || l2 + 1 == l1)) {
					if((l1 == 2 && l2 == 3) || (l1 == 3 && l2 == 2)) {
						cout << 0;
					}
					else {
						cout << 1;
					}
				}
				else {
					cout << 0;
				}
			}
			else {
				cout << "00";
			}
		}
		else {
			cout << "000";
		}
	}
	else {
		cout << "0000";
	}
	return 0;
}
//再给我两分钟
//让我把记忆结成冰
//别让我的眼泪[忘了]
//你妆都花了
//让我怎么记得
//记得你让我忘了吧 
//记得你让我忘了吧 
//你说你会哭
//不是因为 在乎 
