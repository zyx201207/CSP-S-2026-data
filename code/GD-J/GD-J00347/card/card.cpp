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
	int a[200010], pos[200010], ans[200010], desk[200010];
	signed main(void) {
		freopen("card.in", "r", stdin);
		freopen("card.out", "w", stdout);
		int n, m;
		scanf("%d%d", &n, &m);
		rep (i, 1, n) {
			scanf("%d", &a[i]);
		}
		rep (i, 1, n) {
			int siz = 0;
			rep (j, 1, m) {
				pos[j] = 0x3f3f3f3f;
			}
			rep (j, i, n) {
				int card = a[j];
				if (pos[card] > siz) {
					++siz;
					if (desk[siz] != 0) {
						pos[desk[siz]] = 0x3f3f3f3f;
					}
					pos[card] = siz;
					desk[siz] = card;
				} else {
					siz = pos[card];
				}
//				rep (j, 1, siz) {
//					cout << desk[j] << " \n"[j == siz];
//				}
			}
//			cout << endl;
			rep (j, 1, siz) {
				++ans[desk[j]];
				desk[j] = 0;
			}
		}
		rep (i, 1, m) {
			printf("%d%c", ans[i], " \n"[i == m]);
		}
		return 0;
	}
};

signed main(void) {
	return gdb7::main();
}

