#include <bits/stdc++.h>
#define int long long

int c1, c2;
std :: string s1, s2, a, b, aa, bb;

char f (char c) {
	if ('A' <= c && c <= 'C') return '0';
	return '1';
}

void solve () {
	std :: cin >> c1 >> s1;
	std :: cin >> c2 >> s2;
	a = s1[0], b = s2[0];
	a += s1[1], b += s2[1];
	aa = a, bb = b;
	aa += f (s1[2]); bb += f (s2[2]);
	#define p (c1 == c2)
	#define pp (a == b)
	#define ppp (aa == bb)
	#define pppp (abs (s1[2] - s2[2]) == 1)
	std :: cout << p << (p && pp) << (p && pp && ppp) << (p && pp && ppp && pppp);
}

signed main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
//	int TTT; std :: cin >> TTT; while (TTT --)
	solve ();
	
	return 0;
}
