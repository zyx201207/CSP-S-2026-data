#include<bits/stdc++.h>
using namespace std;
//#include<bits/stdc++.h>
//using namespace std;
//
//string s;
//long long n, l;
//long long ans;
//
//int main() {
////	freopen("string.in", "r", stdin);
////	freopen("string.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		int x;
//		char c;
//		cin >> x >> c;
//		l += x;
//		while (x--) s += c;
//	}
//	s = ' ' + s;
//	for (int i = 1, j = l; i <= j; i++, j--)
//		if (s[i] != s[j]) ans++;
//	cout << ans << '\n';
//	return 0;
//}
struct Num {
	int v;
	char c;
}a[200010];
string s;
long long n, l;
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].v >> a[i].c;
		l += a[i].v;
	}
	long long mid = l >> 1;
	long long pos = 0, sum = 0;
	ans = 0;
	int t = n;
	for (int i = 1; i <= t; i++) {
		sum = a[i].v;
		l = pos;
		if (pos + sum > mid) sum = mid - pos, pos = mid;
		else pos += sum;
		for (int j = n; sum && j; j--) {
			if (a[j].v <= sum) {
				sum -= a[j].v;
				if (a[j].c != a[i].c) ans += a[j].v;
				n--;
			} else {
				a[j].v -= sum;
				if (a[j].c != a[i].c) ans += sum;
				sum = 0;
			}
		}
		if (pos == mid) break;
	}
	cout << ans << '\n';
	return 0;
}
