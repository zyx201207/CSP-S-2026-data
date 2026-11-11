#include <bits/stdc++.h>
using namespace std;
int n, m;
string a, b;
int read() {
	int x = 0, f = 1;
	char c = getchar();
	for(;c < 48 || c > 57; c = getchar())
		if(c == '-')
			f = -1;
	for(;c >= 48 && c <= 57; c = getchar())
		x = x * 10 + c - 48;
	return x * f;
}
void write(int x) {
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
	return ;
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n = read();
	cin >> a;
	m = read();
	cin >> b;
	if(n == m) 
		cout << 1;
	else {
		cout << "0000" << endl;
		return 0;
	}
	if(a[0] == b[0] && a[1] == b[1])
		cout << 1;
	else {
		cout << "000" << endl; 
		return 0;
	}
	if(('A' <= a[2] && a[2] <= 'C' && 'A' <= b[2] && b[2] <= 'C')
	|| ('D' <= a[2] && a[2] <= 'F' && 'D' <= b[2] && b[2] <- 'F'))
		cout << 1;
	else {
		cout << "00" << endl;
		return 0;
	}
	if(abs(a[2] - b[2]) < 2 
	|| (a[2] == 'D' && b[2] == 'F')
	|| (a[2] == 'F' && b[2] == 'D'))
		cout << 1;
	else 
		cout << 0;
	cout << endl;
	return 0;
}
