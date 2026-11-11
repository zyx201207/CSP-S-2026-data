#include <bits/stdc++.h>
using namespace std;
class IO {
	char put [35];
	int c, top;
public :
	IO & operator >> (char & ch)
	{
		for (c = getchar (); c == ' ' || c == '\n' || c == '\r'; c = getchar ()) ;
		ch = c;
		return * this;
	}
	IO & operator >> (int & a)
	{
		a = 0;
		for (c = getchar (); c == ' ' || c == '\n' || c == '\r'; c = getchar ()) ;
		for (; 47 < c && c < 58; c = getchar ()) a = (a << 3) + (a << 1) + c - 48;
		return * this;
	}
	IO & operator << (long long p)
	{
		if (p) {
			for (top = 0; p; p /= 10) put [++ top] = p % 10 + 48;
			for (; top; -- top) putchar (put [top]);
		} else putchar ('0');
		return * this;
	}
} IO;
int n, a [200006];
char c [200006];
long long ans;
int main ()
{
	freopen ("string.out", "w", stdout);
	freopen ("string.in", "r", stdin);
	IO >> n;
	for (int i = 1; i <= n; ++ i) IO >> a [i] >> c [i];
	for (int i = 1, j = n; i < j;)
	{
		if (a [i] < a [j]) {
			if (c [i] != c [j]) ans += a [i];
			a [j] -= a [i], ++ i;
		} else if (a [j] < a [i]) {
			if (c [i] != c [j]) ans += a [j];
			a [i] -= a [j], -- j;
		} else {
			if (c [i] != c [j]) ans += a [i];
			++ i, -- j;
		}
	}
	IO << ans;
	return 0;
}
