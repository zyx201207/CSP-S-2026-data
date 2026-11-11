#include <bits/stdc++.h>
using namespace std;
string r1, r2, x1, x2;
void solve();
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r1 >> r2 >> x1 >> x2;
	solve();
	return 0;
}
/*
两张车票对应的座位是否在同一节车厢；
两张车票对应的座位是否在同一节车厢的同一排；
两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
两张车票对应的座位是否相邻。
*/
void solve() {
	if (r1 == x1) { // 车厢
		cout << 1;
		if (r2[0] == x2[0] && r2[1] == x2[1]) { // 排
			cout << 1;
			if ((r2[2] <= 'C' && x2[2] <= 'C') or (r2[2] > 'C' && x2[2] > 'C')) { // 同侧
				cout << 1;
				if (abs(r2[2] - x2[2]) == 1 or (r2[2] > 'C' && x2[2] > 'C')) { // 相邻
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0 << 0;
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}

}
