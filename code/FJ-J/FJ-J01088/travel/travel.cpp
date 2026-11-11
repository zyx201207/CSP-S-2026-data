#include<bits/stdc++.h>
using namespace std;
string ca, cb, sa, sb;
int a[5];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
//	freopen("travel5.in", "r", stdin);
//	freopen("travels.out", "w", stdout);
	cin >> ca >> sa >> cb >> sb;
	if (((ca[0] - '0') * 10 + ca[1] - '0') == ((cb[0] - '0') * 10 + cb[1] - '0')) {
		a[1] = 1;
		if (((sa[0] - '0') * 10 + sa[1] - '0') == ((sb[0] - '0') * 10 + sb[1] - '0')) {
			a[2] = 1;
			if ((sa[2] <= 'C') == (sb[2] <= 'C')) {
				a[3] = 1;
				if (abs(sa[2] - sb[2]) == 1) {
					a[4] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		printf("%d", a[i]);
	}
	return 0;
}
