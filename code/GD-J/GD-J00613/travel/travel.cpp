#include <bits/stdc++.h>
using namespace std;

#define int long long 

int at, bt;
string a, b;
int ah, bh;
char ad, bd;
bool check1(char x, char y) {
	if(x == 'A' || x == 'B' || x == 'C') {
		if(y == 'A' || y == 'B' || y == 'C') {
			return true;
		} else {
			return false;
		}
	} else {
		if(y == 'D' || y == 'F') {
			return true;
		} else {
			return false;
		}
	}
	return false;
}
bool check2(char x, char y) {
	if(x == 'A' || x == 'B' || x == 'C') {
		int xnum = x - 'A', ynum = y - 'A';
		if(abs(xnum - ynum) == 1) {
			return true;
		} else {
			return false;
		}
	} else {
		return true;
	}
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> at >> a >> bt >> b;
	
	ah = (a[0] - '0') * 10 + (a[1] - '0');
	bh = (b[0] - '0') * 10 + (b[1] - '0');
	ad = a[2], bd = b[2];
	
	if(at == bt) {
		cout << "1";
	} else {
		cout << "0";
	}
	
	if(at == bt && ah == bh) {
		cout << "1";
	} else {
		cout << "0";
	}
	
	if(at == bt && ah == bh && check1(ad, bd) == true) {
		cout << "1";
	} else {
		cout << "0";
	}
	
	if(at == bt && ah == bh && check1(ad, bd) == true && check2(ad, bd) == true) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}
