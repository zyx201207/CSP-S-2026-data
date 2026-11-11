#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

//#define DEBUG
#ifdef DEBUG
#define debug(fmt,...) printf(fmt,##__VA_ARGS__)
#else
#define debug(fmt,...)
#endif

struct Node {
	int c;
	int s;
	char sit;
};

/*
01 13B 02 13A
02 03A 02 04B

02 03A 02 03B
02 03A 02 03C
02 03A 02 03D
02 03A 02 03F
02 03B 02 03A
02 03B 02 03C
02 03B 02 03D
02 03B 02 03F

02 03C 02 03A
02 03C 02 03B
02 03C 02 03D
02 03C 02 03F
02 03D 02 03A
02 03D 02 03B
02 03D 02 03C
02 03D 02 03F
02 03F 02 03A
02 03F 02 03B
02 03F 02 03C
02 03F 02 03D

*/

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	Node r,x;
	cin >> r.c;
	string s1;
	cin >> s1;
	r.s = (s1[0] - '0') * 10 + (s1[1] - '0');
	r.sit = s1[2];
	cin >> x.c;
	cin >> s1;
	x.s = (s1[0] - '0') * 10 + (s1[1] - '0');
	x.sit = s1[2];
//	debug("r:%d %d %c\n",r.c,r.s,r.sit);
//	debug("x:%d %d %c\n",x.c,x.s,x.sit);
	if (r.c == x.c) {
		cout << 1;
		if (r.s == x.s) {
			cout << 1;
			if (!(((r.sit == 'A' || r.sit == 'C' || r.sit == 'B') && (x.sit == 'D' || x.sit == 'F')) 
				|| ((x.sit == 'A' || x.sit == 'C' || x.sit == 'B') && (r.sit == 'D' || r.sit == 'F')))) {
			 	cout << 1;
				if ((r.sit == 'A' && x.sit == 'B') || (r.sit == 'B' && x.sit == 'A')
			 	|| (r.sit == 'B' && x.sit == 'C') || (r.sit == 'C' && x.sit == 'B')
			 	|| (r.sit == 'D' && x.sit == 'F') || (r.sit == 'F' && x.sit == 'D')) {
			 		cout << 1;
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}

	return 0;
}
