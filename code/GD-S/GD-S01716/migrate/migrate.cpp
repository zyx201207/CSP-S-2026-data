#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp(x, y) make_pair((x), (y))
#define pp pop_back
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define bk(x) x.back()
#define all(x) x.begin(), x.end()

const int N = 2e6 + 5;

char buf[1 << 20], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
void read(int &x) {
	x = 0;
	int f = 1;
	char ch = gc();
	while (ch < '0' || ch > '9') f = (ch == '-') ? -f : f, ch = gc();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc();
	x *= f;
}
void readll(ll &x) {
	x = 0;
	int f = 1;
	char ch = gc();
	while (ch < '0' || ch > '9') f = (ch == '-') ? -f : f, ch = gc();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc();
	x *= f;
}

bool MemST;

int n;
ll D, a[N] = {0};
int L[N] = {0}, R[N] = {0};
ll pre[N] = {0}, suf[N] = {0};

void init() {
	R[0] = 0, L[n + 1] = n + 1;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j + 1 <= n && a[j + 1] - a[i] <= D) ++j;
		R[i] = j;
	}
	for (int i = n, j = n; i >= 1; i--) {
		while (j - 1 >= 1 && a[i] - a[j - 1] <= D) --j;
		L[i] = j;
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = min(i, L[i + 1]) - L[i];
		if (L[i] < i && R[L[i]] == i) pre[i] += pre[L[i]];
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = R[i] - max(i, R[i - 1]);
		if (R[i] > i && L[R[i]] == i) suf[i] += suf[R[i]];
	}
}

ll cal(int i) {
	int cntl = R[i] - R[i - 1];
	int cntr = L[i + 2] - L[i + 1];
	int u = L[i], v = R[i + 1];
	ll res = 1ll * cntl * cntr;
	bool okl = (u == L[i + 1] && R[u] == i + 1);
	bool okr = (v == R[i] && L[v] == i);
	if (okl) res += pre[u] * cntl;
	if (okr) res += suf[v] * cntr;
	if (okl && okr) res += pre[u] * suf[v];
	return res;
}

bool MemED;

void slv() {
	read(n), readll(D);
	for (int i = 1; i <= n; i++) readll(a[i]);
	init();
	ll ans = 0ll;
	for (int i = 1; i < n; i++) 
		if (L[i] <= i - 1 && R[i] >= i + 2 && L[i + 1] <= i - 1 && R[i + 1] >= i + 2) 
			ans += cal(i);
	printf("%lld\n", ans);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int ID, T;
	read(ID), read(T);
	while (T--) slv();
	return 0;
} 
