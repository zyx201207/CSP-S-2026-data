#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a, b;
string stra, strb;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> a >> stra >> b >> strb;
	bool flag = (a == b);
	cout << flag;
	int la = (stra[0] - '0') * 10 + (stra[1] - '0');
	int lb = (strb[0] - '0') * 10 + (strb[1] - '0');
	flag = (flag && la == lb);
	cout << flag;
	char cha = stra[2], chb = strb[2];
	if (cha > chb) swap(cha, chb);
	flag = (flag && ((cha >= 'A' && chb <= 'C') || (cha == 'D' && chb == 'F')));
	cout << flag;
	flag = (flag && chb - cha == 1);
	cout << flag;
	return 0;
}
