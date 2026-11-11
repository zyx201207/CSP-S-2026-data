#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)
#define per(i, a, b) for (int i = (a); i >= int(b); --i)
#define pb push_back
#define fst first
#define snd second
typedef long long LL;
typedef unsigned long long ULL;
typedef __int128 LLL;
typedef pair<int, int> Pii;

namespace gdb7 {
	signed main(void) {
		freopen("travel.in", "r", stdin);
		freopen("travel.out", "w", stdout);
		string c1, s1, c2, s2;
		cin >> c1 >> s1 >> c2 >> s2;
		if (c1 == c2) {
			if (s1.substr(0, 2) == s2.substr(0, 2)) {
				if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
					if (abs((int)s1[2] - s2[2]) == 1) {
						puts("1111");
					} else {
						puts("1110");
					}
				} else {
					puts("1100");
				}
			} else {
				puts("1000");
			}
		} else {
			puts("0000");
		}
		return 0;
	}
};

signed main(void) {
	return gdb7::main();
}

