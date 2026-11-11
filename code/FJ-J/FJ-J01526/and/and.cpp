#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i = l;i <= r;i++)
using namespace std;

vector <int> bel[40];

int cnt[40];

int a[200005];

int ans;
int n,m;

int qpow(int a, int b) {
	int res = 1;
	int base = a;
	while(b) {
		if (b & 1) res *= base;
		base *= base;
		b >>= 1;
	}
	return res;
}

int Log(int a, int b) {
	int p = 0;
	int l = 0, r = 20;
	while(l <= r) {
		int mid = (l + r) >> 1;
		int t = qpow(a, mid);
		if (t < b) {
			p = mid;
			l = mid + 1;
		}
		else if (t == b) {
			p = mid;
			break;
		}
		else r = mid - 1;
	}
	return p;
}

void F(int x, int s) {
	if (!x) return;
	int t = Log(2, x);
	cnt[t]++;
	bel[t].push_back(s);
	F(x - qpow(2, t), s);
}

bool cmp(int x, int y) {
	return x > y;
}

int main () {
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	
	FOR(i, 1, n) cin >> a[i];
	
	FOR(i, 1, n) {
		F(a[i], a[i]);
	}
	
	int pos = -1;
	for(int i = 32;i >= 0;i--) {
		if (cnt[i] >= m) {
			pos = i;
			break;
		}
	}
	
	if (pos == -1) {
		cout << "0";
		return 0;
	}
	
	sort(bel[pos].begin(), bel[pos].end(), cmp);
	
	ans = bel[pos][0];
	FOR(i, 1, m - 1) ans = ans & bel[pos][i];
	
	cout << ans << '\n';
	
//	FOR(i, 0, 5) cout << cnt[i] << ' ';
	
	return 0;
}
