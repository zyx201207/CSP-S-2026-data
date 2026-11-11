#include <bits/stdc++.h>
using namespace std;
class IO {
	char put [35];
	int c, top;
public :
	IO & operator >> (char & ch)
	{
		for (c = getchar (); c == ' ' || c == '\n' || c == '\r'; c = getchar ());
		ch = c;
		return * this;
	}
	IO & operator >> (int & a)
	{
		for (c = getchar (); c == ' ' || c == '\n' || c == '\r'; c = getchar ());
		for (a = 0; 47 < c && c < 58; c = getchar ()) a = (a << 3) + (a << 1) + c - 48;
		return * this;
	}
	IO & operator >> (string & s)
	{
		for (c = getchar (); c == ' ' || c == '\n' || c == '\r'; c = getchar ());
		for (s = ""; c != ' ' && c != '\n' && c != '\r' && 30 < c; c = getchar ()) s += c;
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
int main ()
{
	freopen ("hub.out", "w", stdout);
	freopen ("hub.in", "r", stdin);
	return 0;
}
