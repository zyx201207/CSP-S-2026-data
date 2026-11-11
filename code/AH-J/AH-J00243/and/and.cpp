#include <bits/stdc++.h>
using namespace std;
class IO {
	char put [35];
	int c, top;
public :
	IO & operator >> (int & a)
	{
		a = 0;
		for (c = getchar (); c == ' ' || c == '\n' || c == '\r'; c = getchar ()) ;
		for (; 47 < c && c < 58; c = getchar ()) a = (a << 3) + (a << 1) + c - 48;
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
int n, m, a [200005], ans;
bool check (int k)
{
	int cnt = 0;
	for (int i = 1; i <= n; ++ i) cnt += ((k & a [i]) == k);
	return m <= cnt;
}
int main ()
{
	freopen ("and.out", "w", stdout);
	freopen ("and.in", "r", stdin);
	IO >> n >> m;
	for (int i = 1; i <= n; ++ i) IO >> a [i];
	for (int k = 1 << 29; k; k >>= 1)
		if (check (ans | k)) ans |= k;
	IO << ans;
	return 0;
}
