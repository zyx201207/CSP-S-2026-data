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
	struct Node {
		int a;
		char c;
	} s[200010];
	signed main(void) {
		freopen("string.in", "r", stdin);
		freopen("string.out", "w", stdout);
		int n;
//		LL L = 0;
		scanf("%d", &n);
		rep (i, 1, n) {
			scanf("%d", &s[i].a);
//			L += s[i].a;
			char ch = getchar();
			while (ch < 'a' || ch > 'z') ch = getchar();
			s[i].c = ch;
		}
//		LL nowL = 0;
		LL ans = 0;
		for (int i = 1, j = n; i < j; ) {
			if (s[i].c == s[j].c) {
				if (s[i].a < s[j].a) {
//					nowL += s[i].a;
					s[j].a -= s[i].a;
					++i;
				} else if (s[i].a == s[j].a) {
//					nowL += s[i].a;
					++i, --j;
				} else {
//					nowL += s[j].a;
					s[i].a -= s[j].a;
					--j;
				}
			} else {
				if (s[i].a < s[j].a) {
//					nowL += s[i].a;
					ans += s[i].a;
					s[j].a -= s[i].a;
					++i;
				} else if (s[i].a == s[j].a) {
//					nowL += s[i].a;
					ans += s[i].a;
					++i, --j;
				} else {
//					nowL += s[j].a;
					ans += s[j].a;
					s[i].a -= s[j].a;
					--j;
				}
			}
		}
		printf("%lld\n", ans);
		return 0;
	}
};

signed main(void) {
	return gdb7::main();
}


