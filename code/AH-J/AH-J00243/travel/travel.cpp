#include <bits/stdc++.h>
using namespace std;
class IO {
	int c;
public :
	IO & operator >> (string & s)
	{
		for (c = getchar_unlocked (); c == ' ' || c == '\n' || c == '\r'; c = getchar_unlocked ()) ;
		for (; 30 < c && c != ' ' && c != '\n' && c != '\r'; c = getchar_unlocked ()) s += c;
		return * this;
	}
	IO & operator << (const char * s) {while (* s) putchar (* s ++); return * this;}
} IO;
string a, b, c, d;
int main ()
{
	freopen ("travel.out", "w", stdout);
	freopen ("travel.in", "r", stdin);
	IO >> a >> b >> c >> d;
	if (a == c) {
		IO << "1";
		if (b [0] == d [0] && b [1] == d [1]) {
			IO << "1";
			if ((b [2] < 'D') == (d [2] < 'D')) {
				IO << "1";
				if (b [2] + 1 == d [2] || b [2] == 1 + d [2]) IO << "1";
				else IO << "0";
			} else IO << "00";
		} else IO << "000";
	} else IO << "0000";
	return 0;
}
