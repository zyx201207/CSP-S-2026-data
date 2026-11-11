#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
string c1, s1, c2, s2;
struct node {int cx, p, c; char bh;} r, x;
int f(string s) {
	return (s[0] - '0') * 10 + s[1];
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	r.cx = f(c1), x.cx = f(c2);//chexiang
	r.p = f(s1), x.p = f(s2);//pai
	r.bh = s1[2], x.bh = s2[2];//bianhao
	if (r.bh == 'F') r.bh = 'E';
	if (x.bh == 'F') x.bh = 'E';
	r.c = (r.bh < 'D'), x.c = (x.bh < 'D');//ce
	if (r.cx == x.cx) {
		cout << 1;
		if (r.p == x.p) {
			cout << 1;
			if (r.c == x.c) 
				cout << 1 << (abs(r.bh - x.bh) == 1);
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
