#include <bits/stdc++.h>
using namespace std;
struct x{
	int a;
	char b;
}s[10000010];
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i].a >> s[i].b;
		x += s[i].a;
	}
	char s1[100010];
	for (int i = 0; i < x; i++) {
		s1[i] = s[i].b;
	}
	int y = 0;
	for (int i = 0; i < x / 2; i++) {
		int sum = x / 2 - 1;
		if (s1[i] != s1[sum]) {
			y++;
		}
		sum--;
	}
	cout << y;
	return 0;
}
