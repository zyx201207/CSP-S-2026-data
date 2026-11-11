#include<bits/stdc++.h>

using namespace std;

struct node {
	int c;
	string s;
};
node R, X;
int a[10];

bool check(char a, char b) {
	bool flag1, flag2;
	if(a == 'A' || a == 'B' || a == 'C') flag1 = 1;
	else flag1 = 0;
	if(b == 'A' || b == 'B' || b == 'C') flag2 = 1;
	else flag2 = 0;
	return flag1 == flag2;
}

bool neibor(char x, char y) {
	if(!check(x, y)) return 0;
	int a = (int)x, b = (int)y;
	if(abs(a - b) == 1) return 1;
	return 0;
}


int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> R.c >> R.s >> X.c >> X.s;
	if(R.c == X.c) a[1] = 1;
	else {
		cout << "0000";
		return 0;
	}
	if(R.s[0] == X.s[0] && R.s[1] == X.s[1]) a[2] = 1;
	else {
		cout << a[1] << "000";
		return 0;
	}
	if(check(R.s[2], X.s[2])) a[3] = 1;
	else {
		cout << a[1] << a[2] << "00";
		return 0;
	}
	if(neibor(R.s[2], X.s[2])) {
		a[4] = 1;
	}
	else {
		cout << a[1] << a[2] <<a[3] << "0"; 
		return 0; 
	}
	cout <<"1111";
	return 0;
}
