#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 200005
#define pb push_back
#define col const ll &
#define coc const char &

struct node {
	ll a;
	char c;
	node (col _a = 0, coc _c = 0) : a (_a), c (_c) {}
};

int n;
ll aa[N], s[N], mid, len, mbkid;
char cc[N];
vector < node > ml, mr;
vector < ll > gl;
vector < char > gc1, gc2;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> aa[i] >> cc[i];
		s[i] = s[i - 1] + aa[i];
	}
	if (s[n] & 1) {
		mid = (s[n] + 1LL) >> 1LL, mbkid = lower_bound(s + 1, s + 1 + n, mid) - s, len = mid - 1LL;
		for (int i = 1; i < mbkid; ml.pb(node(aa[i], cc[i])), ++ i);
		for (int i = n; mbkid < i; mr.pb(node(aa[i], cc[i])), -- i);
		if (s[mbkid - 1] + 1 < mid) {
			ml.pb(node(mid - s[mbkid - 1] - 1, cc[mbkid]));
		}
		if (mid < s[mbkid]) {
			mr.pb(node(s[mbkid] - mid, cc[mbkid]));
		}
	} else {
		mid = s[n] >> 1LL, mbkid = lower_bound(s + 1, s + 1 + n, mid) - s, len = mid;
		for (int i = 1; i < mbkid; ml.pb(node(aa[i], cc[i])), ++ i);
		for (int i = n; mbkid < i; mr.pb(node(aa[i], cc[i])), -- i);
		if (s[mbkid - 1] + 1 < mid) {
			ml.pb(node(mid - s[mbkid - 1], cc[mbkid]));
		}
		if (mid < s[mbkid]) {
			mr.pb(node(s[mbkid] - mid, cc[mbkid]));
		}
	}
	ll sl = 0;
	gl.resize(1);
	for (const node & x : ml) {
		sl += x.a;
		gl.pb(sl);
	}
	sl = 0;
	for (const node & x : mr) {
		sl += x.a;
		gl.pb(sl);
	}
	sort(gl.begin(), gl.end());
	gl.erase(unique(gl.begin(), gl.end()), gl.end());
	int tl = gl.size();
	sl = 0;
	gc1.resize(1), gc2.resize(1);
	for (int i = 0, j = 1; i < (int)ml.size(); ++ i) {
		sl += ml[i].a;
		while (j < tl && gl[j] <= sl) {
			gc1.pb(ml[i].c), ++ j;
		}
	}
	sl = 0;
	for (int i = 0, j = 1; i < (int)mr.size(); ++ i) {
		sl += mr[i].a;
		while (j < tl && gl[j] <= sl) {
			gc2.pb(mr[i].c), ++ j;
		}
	}
	ll ans = 0;
	for (int i = 1; i < tl; ++ i) {
		if (gc1[i] != gc2[i]) {
			ans += gl[i] - gl[i - 1];
		}
	}
	cout << ans << '\n';
	return 0;
}
