#include <bits/stdc++.h>
using namespace std;
#define int long long
#define up(i, a, b) for(int i = a; i <= b; i++)
#define dn(i, a, b) for(int i = a; i >= b; i--)
#define VI vector <int>
struct node{
	int val;
	char id;
};
int compare (vector <node> pre, vector <node> suf) {
	int n1 = pre.size(), n2 = suf.size(), l = 0, r = 0, cnt = 0;
	while (1) {
		if (pre[l].val <= suf[r].val) {
			if (pre[l].id != suf[r].id) cnt += pre[l].val;
			suf[r].val -= pre[l].val, l++;
		}
		if (suf[r].val <= pre[l].val) {
			if (pre[l].id != suf[r].id) cnt += suf[r].val;
			pre[l].val -= suf[r].val, r++;
		}
		if (l == n1 || r == n2) {
			return cnt;
		}
	}
	return cnt;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, len = 0; cin >> n;
	bool ji = 0;
	vector <node> a(n + 1), pre, suf;
	up (i, 1, n){
		cin >> a[i].val >> a[i].id;
		len += a[i].val;
	}
	ji = (len % 2);
	//int lens = len;
	len = len / 2 + (len % 2);
	up (i, 1, n) {
		if (a[i].val <= len) {
			if (pre.empty()) pre.push_back(a[i]);
			else if (pre.back().id == a[i].id) pre.back().val += a[i].val;
			else pre.push_back(a[i]);
			len -= a[i].val;
		}
		else if (len > 0) {
			if (pre.back().id == a[i].id) pre.back().val += len;
			else pre.push_back({len, a[i].id});
			suf.push_back({a[i].val - len, a[i].id});
			len = 0;
		}
		else {
			if (suf.empty()) suf.push_back(a[i]);
			else if (suf.back().id == a[i].id) suf.back().val += a[i].val;
			else suf.push_back(a[i]);
		}
	}
	if (ji) pre.back().val--;
	if (pre.back().val == 0) pre.pop_back();
	reverse(suf.begin(), suf.end());
//	for (auto &i : pre) cout << i.val << " " << i.id << endl;
//	cout<< "###########################################"<< endl;
//	for (auto &i : suf) cout << i.val << " " << i.id << endl;
	int ans = compare(pre, suf);
	cout << ans;
	return 0;
}

