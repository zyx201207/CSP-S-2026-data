#include <iostream>
#include <cctype>
#define gc getchar
#define pc putchar
#define int long long
using namespace std;
int a, b, c, d, e, f;
bool g;
inline void rd(int &x, int &s) {
	int sum = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
	for (; isdigit(c); c = gc()) sum = sum * 10 + c - '0';
	for (; isupper(c); c = gc()) s = c;
	x = sum * f;
}
inline void wt(int x) {
	if (x > 9) wt(x/10);
	pc(x%10+'0');
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	rd(a, e);rd(b, e);rd(c, f);rd(d, f);
	wt(g=(a==c));
	wt(g=g&&(b==d));
	wt(g=g&&(max(e,f)<='C'||min(e,f)>='D'));
	wt(g&&(e-f==1||f-e==1));
	return 0;
}
