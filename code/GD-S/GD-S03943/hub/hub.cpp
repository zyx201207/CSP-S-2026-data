#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int read() {
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return ans;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c = read(), T = read();
	while (T--) {
		int n = read(), m = read();
		for (int i = 1; i < n; ++i) {
			int x = read(), y = read();
		}
		cout << (n - m * 2 + 3) / 8 << endl;
	} 
	return 0;
} 
