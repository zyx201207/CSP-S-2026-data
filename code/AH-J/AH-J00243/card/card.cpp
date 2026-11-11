#include <bits/stdc++.h>
using namespace std;
class IO {
	char put [35];
	int c, top;
public :
	IO () {freopen ("card.out", "w", stdout); freopen ("card.in", "r", stdin);}
	IO & operator >> (int & a)
	{
		a = 0;
		for (c = getchar_unlocked (); c == ' ' || c == '\n' || c == '\r'; c = getchar_unlocked ()) ;
		for (; 47 < c && c < 58; c = getchar_unlocked ()) a = (a << 3) + (a << 1) + c - 48;
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
} IO;
int m, ans [300007], w [500009];
int nxt [500009], b [300007];
int n, a [500009];
int main ()
{
	IO >> n >> m;
	for (int i = 1; i <= n; ++ i)
		IO >> a [i], nxt [b [a [i]]] = i, b [a [i]] = i;
	for (int i = 1; i <= n; ++ i)
	{
		++ w [i];
		if (nxt [i]) w [nxt [i]] += w [i];
		else ans [a [i]] += w [i], w [i + 1] += w [i];
	}
	for (int i = 1; i <= m; ++ i) IO << ans [i] << ' ';
	return 0;
}
