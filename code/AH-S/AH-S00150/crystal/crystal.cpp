#include <bits/stdc++.h>
using namespace std;
class IO {
	char put [35];
	int c, top;
public :
	IO & operator >> (char & ch)
	{
		for (c = getchar_unlocked (); c == ' ' || c == '\n' || c == '\r'; c = getchar_unlocked ());
		ch = c;
		return * this;
	}
	IO & operator >> (int & a)
	{
		for (c = getchar_unlocked (); c == ' ' || c == '\n' || c == '\r'; c = getchar_unlocked ());
		for (a = 0; 47 < c && c < 58; c = getchar_unlocked ()) a = (a << 3) + (a << 1) + c - 48;
		return * this;
	}
	IO & operator >> (long long & a)
	{
		for (c = getchar_unlocked (); c == ' ' || c == '\n' || c == '\r'; c = getchar_unlocked ());
		for (a = 0; 47 < c && c < 58; c = getchar_unlocked ()) a = (a << 3) + (a << 1) + c - 48;
		return * this;
	}
	IO & operator >> (string & s)
	{
		for (c = getchar_unlocked (); c == ' ' || c == '\n' || c == '\r'; c = getchar ());
		for (s = ""; c != ' ' && c != '\n' && c != '\r' && 30 < c; c = getchar_unlocked ()) s += c;
		return * this;
	}
	IO & operator << (const int & a)
	{
		unsigned long long p = a;
		if (a < 0) putchar ('-'), p = - p;
		if (a) {
			for (top = 0; p; p /= 10) put [++ top] = p % 10 + 48;
			for (; top; -- top) putchar (put [top]);
		} else putchar ('0');
		return * this;
	}
	IO & operator << (const char & c) {putchar (c); return * this;}
	IO & operator << (const char * s) {while (* s) putchar (* s ++); return * this;}
} IO;
long long m, a [500009];
int n, ans;
int main ()
{
	freopen ("crystal.out", "w", stdout);
	freopen ("crystal.in", "r", stdin);
	IO >> n >> m;
	for (int i = 1; i <= n; ++ i) IO >> a [i];
	sort (a + 1, a + n + 1);
	for (int i = 1, j = 1; i <= n; ++ i)
	{
		 m -= (i - j) * (a [i] - a [i - 1]);
		 while (m < 0) m += a [i] - a [j], ++ j;
		 ans = max (ans, i - j + 1);
	}
	IO << ans;
	return 0;
}
