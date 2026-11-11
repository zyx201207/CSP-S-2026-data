#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int N = 3e5 + 1;

int n, ans, sum;

struct ipt { int st, ed; char typ; } ipts[N];

vector<ipt> index[31];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; char c; cin >> a >> c;
		ipts[i].st = sum + 1, ipts[i].ed = sum + a, ipts[i].typ = c;
		index[c - 'a'].push_back(ipts[i]); sum += a;
	} ans = sum >> 1;
	for (int i = 1; i <= n; i++) {
		if (ipts[i].st > (sum >> 1)) break;
		if (ipts[i].ed > (sum >> 1)) ipts[i].ed = sum >> 1;
		int fs = sum - ipts[i].ed + 1, fe = sum - ipts[i].st + 1;
		for (ipt p : index[ipts[i].typ - 'a']) {
			if (p.st > fe || p.ed < fs) continue;
			else ans -= min(fe, p.ed) - max(fs, p.st) + 1;
		}
	} cout << ans;
	return 0;
}
