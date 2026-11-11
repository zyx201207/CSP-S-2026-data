#include <iostream>
#include <algorithm>
using namespace std;
long long to_10(string a) {
	long long n = 0, s = 1;
	for(int i = a.size() - 1; i >= 0; i--) {
		n += (a[i] != 0) * s;
		s *= 2;
	}
	return n;
}
int n, m, s, l, ans;
string a[200005], xs;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		xs = "";
		while(s) {
			xs += s % 2 + '0';
			s /= 2;
		}
		l = xs.size() - 1;
		for(int j = l; j >= 0; j--) {
			a[i] += xs[j];
		}
	}
	sort(a + 1, a + 1 + n);
	xs = a[n - m + 1];
	int lx = xs.size() - 1;
	s = 1;
	ans = 0;
	for(int i = n - m + 2; i <= n; i++) {
		l = a[i].size() - 1;
		for(int j = lx; j >= 0; j--) {
			if(a[i][l - lx + j] == '0') {
				xs[j] = '0';
			}
			if(i == n) {
				ans += (xs[j] != '0') * s;
				s *= 2;
			}
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

