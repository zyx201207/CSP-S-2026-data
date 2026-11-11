#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
//	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	int n, idx = 0;
	LL tar = 0, sum = 0;
	cin >> n;
	vector<LL> a;
	vector<char> c;
	queue<LL> qa, qb;
	queue<char> qac, qbc;
	LL x;
	char chx, pre = '0';
	for (int i = 0; i < n; i++) {
		cin >> x >> chx;
		if (chx == pre) a[a.size() - 1] += x;
		else {
			a.push_back(x);
			c.push_back(chx);
		} tar += x;
	} if (a.size() == 1) {
		cout << 0;
		return 0;
	} n = a.size();
	for ( ;sum + a[idx] <= tar / 2; idx++) sum += a[idx];
	if (tar & 1) a[idx + 1]--;
	if (sum == tar / 2) {
		idx -= 1;
		for (int i = 0; i <= idx; i++) {
			qa.push(a[i]);
			qac.push(c[i]);
		} for (int i = n - 1; i > idx; i--) {
			qb.push(a[i]);
			qbc.push(c[i]);
		}
	} else {
		for (int i = 0; i < idx; i++) {
			qa.push(a[i]);
			qac.push(c[i]);
		} for (int i = n - 1; i > idx; i--) {
			qb.push(a[i]);
			qbc.push(c[i]);
		} int fned = tar / 2 - sum, sned = a[idx] - fned;
		if (fned != sned) {
			qa.push(abs(fned - sned));
			qac.push(c[idx]);
		}
	} LL need = qa.front();
	char ch = qac.front();
	qa.pop(), qac.pop();
	LL ans = 0;
	while (!qa.empty() || !qb.empty()) {
		if (!need) {
			need = qa.front();
			ch = qac.front();
			qa.pop(), qac.pop();
		} if (need > 0) {
			LL minus = qb.front();
			char chx = qbc.front();
			cout << need << ch << " " << minus << qbc.front() << endl;
			qb.pop(), qbc.pop();
			if (ch != chx) ans += minus;
			if (need < minus) ch = chx;
			need -= minus;
		} else {
			LL minus = qa.front();
			char chx = qac.front();
			cout << need << ch << " " << minus << qbc.front() << endl;
			qa.pop(), qac.pop();
			if (ch != chx) ans += minus;
			if (need > minus) ch = chx;
		}
	} cout << ans;
}

