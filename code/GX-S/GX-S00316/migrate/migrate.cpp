#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000007;
const ll ee = 1e18;
int n, R[maxn], f0[maxn], f1[maxn], g[maxn], h[maxn], f2[maxn];
ll a[maxn], d;
bool vis[maxn];
void calc(int i) {
	int fi = R[i], ffi = R[R[i]];
	if (fi == ffi) return;
	f0[i] = f0[fi], f1[i] = f1[fi], f2[i] = f2[fi];
	g[i] = g[fi], h[i] = h[fi];
	int p1, p2, flg = 0;
	if (fi - 1 > i) p2 = R[fi - 1];
	else p2 = fi;
	if (fi - 2 > i) p1 = R[fi - 2];
	else p1 = fi;
	if (p1 == ffi && p2 == ffi) {
		g[i] = h[i] = R[i];
	} else if (p2 == ffi) {
		h[i] = g[i];
		g[i] = R[i];
		f1[i] += ffi - p1;
		f2[i] += ffi - p1;
	} else {
		f0[i] += ffi - p2;
		f1[i] += p2 - p1;
		f2[i] += p2 - p1;
		if (p2 == ffi - 1) {
			f1[i] += f2[ffi] - f2[fi];
			h[i] = g[i];
		}
	}
}
ll solve(void) {
	long long res = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		g[i] = h[i] = n + 1;
		f0[i] = f1[i] = f2[i] = 0;
	}
	g[n + 1] = h[n + 1] = n + 1;
	f0[n + 1] = f1[n + 1] = f2[n + 1] = 0;
	for (int i = 1, cur = 1; i <= n; i++) {
		for (; cur <= n && a[cur] - a[i] <= d; cur++);
		R[i] = cur - 1;
	}
	R[n + 1] = n + 1;
	for (int i = n; i >= 1; i--) {
		calc(i);
		res += f1[i] - f1[g[i]] + f0[g[i]] - f0[h[i]];
	}
	/*for (int i = 1; i <= n; i++) {
		cout << g[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << h[i] << " ";
	}
	cout << "\n";*/
	/*for (int i = 1; i <= n; i++) {
		cout << f1[i] - f1[g[i]] + f0[g[i]] - f0[h[i]] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << f1[i] << " ";
	}
	cout << "\n";*/
	return res;
}
namespace T1 {
	int cmin;
	vector<int> st;
	map<vector<int>, bool> pm;
	void dfs(int x, int tar, int stp) {
		if (x == tar) {
			if (stp < cmin) cmin = stp, pm.clear();
			else if (stp > cmin) return;
			pm[st] = 1;
			return;
		}
		st.emplace_back(x);
		for (int i = x + 1; i <= min(tar, R[x]); i++) {
			dfs(i, tar, stp + 1);
		}
		st.pop_back();
	}
	int calc(int i) {
		int sum = 0;
		pm.clear();
		for (int j = i + 1; j <= n; j++) {
			pm.clear(), st.clear(), cmin = n + 1;
			dfs(i, j, 0);
			if (pm.size() == 2) sum++;
			/*if (i == 1 && j == 9) {
				for (auto x : pm) {
					for (auto y : x.first) cout << y << " ";
					cout << "\n";
				}
			}*/
		}
		//cout << i << " " << sum << "\n";
		return sum;
	}
	ll solve(void) {
		long long res = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1, cur = 1; i <= n; i++) {
			for (; cur <= n && a[cur] - a[i] <= d; cur++);
			R[i] = cur - 1;
		}
		for (int i = 1; i <= n; i++) {
			res += calc(i);
		}
		return res;
	}
}
namespace T2 {
	int calc(int i) {
		int st = i, fi = R[i], ffi = R[R[i]];
		if (fi == ffi) return 0;
		int sum = 0, p1, p2, flg = 0, flg2 = 0;
		for (; fi != ffi; ) {
			if (fi - 1 > i) p2 = R[fi - 1];
			else p2 = fi;
			if (fi - 2 > i) p1 = R[fi - 2];
			else p1 = fi;
			//cout << st << " " << fi << " " << ffi << " " << p1 << " " << p2 << " " << flg2 << "\n";
			if (p1 == ffi && p2 == ffi) break;
			else if (p2 == ffi) {
				if (flg || flg2) break;
				flg = 1, flg2 = 0;
				sum += ffi - p1;
			} else {
				if (flg) sum += ffi - p2;
				else if (!flg2) sum += p2 - p1/*, cout << "QWQ\n"*/;
				if (p2 == ffi - 1) flg2 = 1;
				else flg2 = 0;
			}
			i = fi, fi = ffi, ffi = R[ffi];
		}
		//cout << st << " " << sum << "\n";
		return sum;
	}
	ll solve(void) {
		long long res = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1, cur = 1; i <= n; i++) {
			for (; cur <= n && a[cur] - a[i] <= d; cur++);
			R[i] = cur - 1;
		}
		//for (int i = 1; i <= n; i++) cout << R[i] << " ";
		//cout << "\n";
		for (int i = 1; i <= n; i++) {
			res += calc(i);
		}
		//cout << "\n";
		return res;
	}
}
int main(void) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	int cid, T;
	cin >> cid >> T;
	for (; T--; ) {
		if (cid <= 2) cout << T1::solve() << "\n";
		else if (cid <= 10) cout << T2::solve() << "\n";
		else cout << solve() << "\n";
	}

	return 0;
}