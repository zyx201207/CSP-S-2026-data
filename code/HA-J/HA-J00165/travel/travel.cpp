#include<bits/stdc++.h>
using namespace std;
/*
guanzhu _Liyx_ miao
AC at ?:?
*/
int a, b;
string sa, sb;
bool ans[5];
bool xx(char c) {
	if (c == 'A' || c == 'B' || c == 'C') return 1;
	else return 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> sa >> b >> sb;
	ans[1] = (a == b);
	ans[2] = ((sa[0] - '0') * 10 + (sa[1] - '0') == (sb[0] - '0') * 10 + (sb[1] - '0')) & ans[1];
	ans[3] = (xx(sa[2]) == xx(sb[2])) & ans[2];
	ans[4] = (abs((int)sa[2] - (int)sb[2]) == 1) & ans[3];
	cout << ans[1] << ans[2] << ans[3] << ans[4];
	return 0;
}
