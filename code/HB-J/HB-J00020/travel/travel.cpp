#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 50;
char s1[N], s2[N];
int c1, c2;

bool TYC (char a, char b) {
	if (a == 'C' && b == 'D') return false;
	if (a == 'D' && b == 'C') return false;
	return true;
}

bool XL (char a, char b) {
	if (a == 'C' && b == 'A') return false;
	if (a == 'A' && b == 'C') return false;
	return true;
}

signed main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	int Rpai = s1[0]*10+s1[1], Xpai = s2[0]*10+s2[1];
	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
	
	if (c1 == c2) {
		ans1 = 1;
		if (Rpai == Xpai) {
			ans2 = 1;
			if (TYC(s1[2], s2[2])) {
				ans3 = 1;
				if (XL(s1[2], s2[2])) {
					ans4 = 1;
				}
				else ans4 = 0;
			}
			else ans3 = 0;
		}
		else ans2 = 0;
	}
	else ans1 = 0;
	
	printf("%lld%lld%lld%lld", ans1, ans2, ans3, ans4);
	return 0;
}
