#include <bits/stdc++.h>
using namespace std;

inline long long read(void) {
	long long x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - 48, c = getchar();
	return x * f;
}

long long c, T, n, k, u, v, d1, d2, mid, ans, cnt, _[1000005], d[1000005], g1[1000005][20], g2[1000005][20], nxt[1000005], h[1000005][2], f[1000005][2];
vector<long long> nt[1000005];
bool flag[1000005];

pair<long long, long long> dfs (long long x, long long pre) {
	pair<long long, long long> rtn = {x, 0};
	for (auto i : nt[x]) {
		if (i == pre) continue;
		pair<long long, long long> _dfs = dfs(i, x);
		if (_dfs. second + 1 > rtn. second) rtn = _dfs, nxt[x] = i;
	}
	return rtn;
}

void init (long long x, long long pre, bool type) {
	h[x][type] = 0;
	for (auto i : nt[x]) {
		if (i == pre) continue;
		init(i, x, type);
		h[x][type] = max(h[x][type], h[i][type] + 1);
	}
	f[x][type] = 1;
	for (auto i : nt[x]) if (i != pre && h[i][type] >= mid) f[x][type] += f[i][type];
}

long long init2 (long long x, long long pre) {
	long long rtn = 0;
	for (auto i : nt[x]) if (!flag[i] && i != pre) rtn = max(rtn, init2(i, x) + 1);
	return rtn;
}

long long query (long long l, long long r) {
	long long _s = _[r - l + 1];
	return max(g1[l][_s], g1[r - (1 << _s) + 1][_s]);
}

long long query2 (long long l, long long r) {
	if (l > r) return -r;
	long long _s = _[r - l + 1];
	return max(g2[l][_s], g2[r - (1 << _s) + 1][_s]);
}

bool check (long long l, long long r) {
//	long long md = l + r >> 1;
//	return max(query(l, md) - l + 1, r + query2(md + 1, r) + 1) <= mid;
	for (int i = l; i <= r; i++) if (max(g1[i][0] - l + 1, g2[i][0] + r + 1) > mid) return 0;
	return 1;
}

int main(void) {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	for (int i = 2; i <= 1000000; i++) _[i] = _[i >> 1] + 1;
	c = read(), T = read();
	while (T--) {
		n = read(), k = read(), cnt = 0;
		for (int i = 1; i <= n; i++) nt[i]. clear(), flag[i] = 0;
		for (int i = 1; i < n; i++) u = read(), v = read(), nt[u]. push_back(v), nt[v]. push_back(u);
		d2 = dfs(1, 0). first, d1 = dfs(d2, 0). first;
		for (int i = d2; ; i = nxt[i]) {
			d[++cnt] = i, flag[i] = 1;
			if (i == d1) break;
		}
		for (int i = 1; i <= cnt; i++) {
			long long s = init2(d[i], 0);
			g1[i][0] = s + i;
			g2[i][0] = s - i;
		}
		for (int i = 1; 1 << i <= n; i++)
			for (int j = 1; j + (1 << i) - 1 <= n; j++)
				g1[j][i] = max(g1[j][i - 1], g1[j + (1 << i)][i - 1]),
				g2[j][i] = max(g2[j][i - 1], g2[j + (1 << i)][i - 1]);
		long long l = 0, r = n;
		while (l <= r) {
			mid = l + r >> 1;
			init(d1, 0, 0), init(d2, 0, 1);
			bool flag = 0;
			int _r = 1;
			for (int i = 1; i < cnt; i++) {
				_r = max(_r, i + 1);
				while (_r < cnt && check(i + 1, _r)) _r++;
				if (f[d[i]][0] + f[d[_r]][1] <= k) {
					flag = 1;
					break;
				}
			}
			for (int i = 1; i <= cnt; i++) {
				if (i == cnt || query(i + 1, cnt) - i <= mid) {
					if (f[d[i]][0] <= k) {
						flag = 1;
						break;
					}
				}
			}
			if (flag) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
