#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

struct ticket {
	int c;
	string seat;
	pair<int, char> get_seat() {
		pair<int, char> res;
		sscanf(seat.c_str(), "%d%c", &res.first, &res.second);
		return res;
	}
	friend istream &operator>>(istream &inputer, ticket &a) {
		inputer >> a.c >> a.seat;
		return inputer;
	}
}r,x;
pair<int, char> rp,xp;
bool b1,b2,b3,b4;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r >> x;
	rp = r.get_seat();
	xp = x.get_seat();
	b1 = (r.c == x.c);
	b2 = (b1 && (rp.first == xp.first));
	b3 = (b2 && ((rp.second <= 'C') == (xp.second <= 'C')));
	b4 = (b3 && ((rp.second + 1 == xp.second) || (rp.second - 1 == xp.second)));
	cout << b1 << b2 << b3 << b4 << endl;
	return 0;
}

