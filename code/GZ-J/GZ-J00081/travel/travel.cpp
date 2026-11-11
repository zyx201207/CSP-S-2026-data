//GZ-J00081 贵阳市第一中学 王羿翔 
#include <bits/stdc++.h>
using namespace std;
string a, b, c, d; 
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1;
		if (b[0]==d[0]&&b[1]==d[1]) {
			cout << 1;
			char x = b[2], y = d[2];
			if ((x<='C'&&y<='C')||(x>='D'&&y>='D')) {
				cout << 1;
				if (x+1==y||y+1==x||(x=='D'&&y=='F')||(x=='F'&&y=='D'))
					cout << 1;
				else cout << 0;
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}
