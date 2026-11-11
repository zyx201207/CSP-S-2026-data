//Òª¼ÇµÃÐ´ 
//freopen(" .in", "r", stdin);
//freopen(" .out", "w", stdout);

#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005], cnt, l, r, c1=1, c2;
string s;
char opt[200005];

int main() {
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	c2 = n;
	for (int i=1;i<=n;i++) {
		int x;
		char ch;
		cin >> x >> ch;
		a[i] = a[i-1] + x;
		opt[i] = ch; 
		r += x;
	}
	l = 1;
	while (l <= r) {
		char op1, op2;
		if (l > a[c1]) c1 ++;
		op1 = opt[c1];
		if (r <= a[c2-1]) c2 --;
		op2 = opt[c2];
		if (op1 != op2) cnt ++;
		l++; r--;
	}
	cout << cnt;
	
	return 0;
} 
