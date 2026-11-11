#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
struct node {
	long long x;
	char c;
	node (long long x, char c): x(x), c(c) {}
	node () {}
};
int n;
node a[maxn];
long long slen;
vector <node> ls, rs;
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].c;
		slen += a[i].x;
	}
//	cout << slen << endl;
	slen /= 2;
	long long cntl = 0, cntr = 0;
	for (int i = 1; i <= n; i++) {
		cntl += a[i].x;
		if (cntl >= slen) {
//			cout << cntl << "Lep" << endl;
			ls.push_back (node (a[i].x - cntl + slen, a[i].c));
//			cout << i << " \'" << a[i].c << "\'" << " " << a[i].x << endl;
			break;
		} else {
			ls.push_back (node (a[i].x, a[i].c));
		}
	}
//	for (auto i : ls){
//		cout << i.x << " " << i.c << endl;
//	}
	for (int i = n; i >= 1; i--) {
		cntr += a[i].x;
		if (cntr >= slen) {
//			cout << cntr << "Rep" << endl;
//			cout << i << " \'" << a[i].c << "\'" << endl;
			rs.push_back (node (a[i].x - cntr + slen, a[i].c));
			break;
		} else {
			rs.push_back (node (a[i].x, a[i].c));
		}
	}
//	cout << cntl << " | " << cntr << endl;
	if (ls.empty()) {
		cout << 0 << flush;
		return 0;
	}
	int L = 0, R = 0;
	long long ans = 0;
	long long sul = ls[0].x, sur = rs[0].x;
	while (R < rs.size() && L < ls.size()) {
		if (sul > sur) {
			if (ls[L].c != rs[R].c) {
				ans += sur;
			}
			sul -= sur;
			R++;
			sur = rs[R].x;
		} else if (sul == sur) {
			if (ls[L].c != rs[R].c) {
				ans += sur;
			}
			L++, R++;
			sur = rs[R].x;
			sul = ls[L].x;
		} else {
			if (ls[L].c != rs[R].c) {
				ans += sul;
			}
			sur -= sul;
			L++;
			sul = ls[L].x;
		}
	}
//	cout << L << " " << R << " " << ls.size() << " " << rs.size() << " " << slen << endl;
//	L++;
//	while (L < ls.size()){
//		cout << ls[L].x << " \'" << ls[L].c << "\'\n";
//		L++;
//	}
//	cout << endl;
//	long long asl = 0, asr = 0;
//	for (node x : ls){
//		asl += x.x;
//	}
//	for (node x : rs){
//		asr += x.x;
//	}
//	cout << asl << " " << asr << endl;
	cout << ans << flush;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
