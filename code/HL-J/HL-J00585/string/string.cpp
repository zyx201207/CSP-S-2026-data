#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
long long a[N];
char op[N];
long long ans = 0LL;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		int tmp; char ch;
		//scanf("%d%c", & tmp, & ch);
		cin >> a[i] >> ch;
		op[i] = ch;
	}
	int cl = 1, cr = n;
	while(cl < cr) {
		int wl = a[cl];
		int wr = a[cr];
		//cout << wl << " " << wr << "\n";
		if (op[cl] != op[cr]) ans += min(wl, wr);
		if (wl > wr) {
			cr--;
			a[cl] = wl - wr;
		} else if (wl < wr) {
			cl++;
			a[cr] = wr - wl;
		}else {
			cl++, cr--;
		}
	} 
	cout << ans << "\n";
	return 0;
} 
