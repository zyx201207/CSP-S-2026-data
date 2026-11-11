#include <bits/stdc++.h>
using namespace std;
//using int = long long;
int n, m;
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
	n = read();
	write(n);
	return 0;
}
