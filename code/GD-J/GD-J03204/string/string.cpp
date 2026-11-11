#include<bits/stdc++.h>
using namespace std;
using ull = long long;
const int N = 2e5 + 10;
int n, a[N], ll, lr, cl, cr, pos;
char s[N], c;
ull sum = 0, ss, lst, ans;
struct edge {
	ull cnt;
	char val;
}l[N], r[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c;
		s[i] = c;
		sum += a[i];
	}
	for(int i = 1; i <= n; i++) {
		ss += a[i];
		if(ss > sum / 2) {
			l[++ll] = {sum / 2 - lst, s[i]};
			pos = i;
			break;
		}
		else l[++ll] = {a[i], s[i]};
		lst = ss;
	} 
	for(int i = n; i > pos; i--) r[++lr] = {a[i], s[i]};
	r[++lr] = {ss - sum / 2, s[pos]};
	cl = cr = 1;
	while((cl <= ll && cr <= lr)) {
		if(l[cl].cnt < r[cr].cnt) {
			r[cr].cnt -= l[cl].cnt;
			ans += (l[cl].val != r[cr].val ? 1LL : 0LL) * l[cl].cnt;
			l[cl++].cnt = 0;
		}
		else {
			l[cl].cnt -= r[cr].cnt;
			ans += (l[cl].val != r[cr].val ? 1LL : 0LL) * r[cr].cnt;
			r[cr++].cnt = 0;
		}
	}
	cout << ans;
	return 0;
}
