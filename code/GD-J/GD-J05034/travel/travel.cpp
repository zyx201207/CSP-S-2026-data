#include<bits/stdc++.h>
using namespace std;
int c1, c2, sa1, sa2, a[7];
char sb1, sb2;
string t1, t2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> t1 >> c2 >> t2;
	sa1 = (t1[0] - '0') * 10 + (t1[1] - '0'), sb1 = t1[2];
	sa2 = (t2[0] - '0') * 10 + (t2[1] - '0'), sb2 = t2[2];
	if (c1 == c2) {
		a[0] = 1;
		if (sa1 == sa2) {
			a[1] = 1;
			if ((sb1 <= 'C' && sb2 <= 'C') || (sb1 > 'C' && sb2 > 'C')) {
				a[2] = 1;
				if (abs(sb1 - sb2) == 1 && !(sb1 == 'C' && sb2 == 'D') && !(sb1 == 'D' && sb2 == 'C')) 
					a[3] = 1;
			}
		}
	}
	cout << a[0] << a[1] << a[2] << a[3];
	return 0;
}
