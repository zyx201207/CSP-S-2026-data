#include <bits/stdc++.h>
using namespace std;
class IO {
	char put [35];
	int c, top, f;
public :
	IO & operator >> (int & a)
	{
		scanf ("%d", & a);
		return * this;
	}
	IO & operator >> (long long & a)
	{
		scanf ("%lld", & a);
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
	IO & operator << (const long long & a)
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
long long Sl [200007], Sr [200007];
int L [200007], R [200007];
long long d, a [200007];
long long Ans;
int c, t, n;
int main ()
{
	freopen ("migrate.out", "w", stdout);
	freopen ("migrate.in", "r", stdin);
	IO >> c;
	for (IO >> t; t; -- t)
	{
		IO >> n >> d, Ans = 0;
		for (int i = 0; i <= n + 7; ++ i) Sl [i] = Sr [i] = 0;
		a [0] = - 0x3f3f3f3f3f3f3f3f, a [n + 1] = 0x3f3f3f3f3f3f3f3f;
		for (int i = 1; i <= n; ++ i) IO >> a [i];
		for (int i = n + 1, o = n + 1; ~ i; -- i)
		{
			for (; a [i] + d < a [o];) -- o;
			R [i] = o;
		}
		for (int i = 0, o = 0; i <= n + 1; ++ i)
		{
			for (; a [o] + d < a [i];) ++ o;
			L [i] = o;
		}
		for (int i = 1; i < n; ++ i)
		{
			int l = L [i], r = min (L [i + 1], i);
			Sl [i] = r - l;
			if (l < r) Sl [i] += Sl [l];
			//[)
		}
		for (int i = n; i > 1; -- i)
		{
			int l = max (R [i - 1], i), r = R [i];
			Sr [i] = r - l;
			if (l < r) Sr [i] += Sr [r];
			//(]
		}
		for (int i = 1; i <= n; ++ i) if (L [i] != i && R [i + 1] != i + 1) Ans += Sr [i] * Sl [i + 1];
		IO << Ans << '\n';
	}
	return 0;
}
