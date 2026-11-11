#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a != c) {
		cout << "0000";
		return 0;
	}
	cout << "1";
	string x = "", y = "";
	x = x + b[0] + b[1], y = y + d[0] + d[1];
	if (x != y){
		cout << "000";
		return 0;
	}
	cout << "1";
	if (!((b[2] <= 'C' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >= 'D'))){
		cout << "00";
		return 0;
	}
	cout << "1";
	if (abs(b[2] - d[2]) == 1 || ((b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D'))){
		cout << "1";
		return 0;
	}
	cout << "0";
	return 0;
}
/*
感觉会挂是为啥。 
11:42
不是
真错了啊，幸好我看了。
你这个座位怎么没有 E 啊。
直接 abs 是错的。 
*/ 
