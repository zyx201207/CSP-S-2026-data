#include<bits/stdc++.h>
using namespace std;
int ib, id;
char cb, cd;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

//	ios::sync_with_stdio(false);
//	cin.tie(nullptr), cout.tie(nullptr);

	int a, c;
	string b, d;
	cin >> a >> b >> c >> d;
	ib = (b[0] - '0') * 10 + (b[1] - '0');
	id = (d[0] - '0') * 10 + (d[1] - '0');
	cb = b[2], cd = d[2];
	int kl = 0, kr = 0;
	if(cb == 'A' || cb == 'B' || cb == 'C') kl = 1;
	if(cd == 'A' || cd == 'B' || cd == 'C') kr = 1;

	if(a == c) {
		if(ib == id) {
			if(kl == kr) {
				if(cb + 1 == cd || cd + 1 == cb)
					cout << "1111";
				else cout << "1110";
			} else cout << "1100";
		} else cout << "1000";
	} else cout << "0000";

	return 0;
}
