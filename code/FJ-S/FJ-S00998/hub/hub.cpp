#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')
			f = -1; c = getchar();
	} while (isdigit(c))
		x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int n, k, L, R, dL[1000001], dR[1000001], h[1000001];
int faL[1000001], faR[1000001], mxdL[1000001], mxdR[1000001], vL[1000001], vR[1000001];
vector<int > T[1000001];

void dfs(int *fa, int *d, int u, int f) {
	fa[u] = f, d[u] = d[f] + 1;
	for (int v : T[u])
		if (v != f)
			dfs(fa, d, v, u);
}

void ah(int u, int f) {
	for (int v : T[u]) 
		if (v != f) {
			ah(v, u);
			if (h[v])
				h[u] = 1;
		}
}

void mx(int *d, int *mxd, int u, int f) {
	mxd[u] = d[u];
	for (int v : T[u])
		if (v != f)
			if (h[v])
				mx(d, mxd, v, u);
			else
				mx(d, mxd, v, u), mxd[u] = max(mxd[u], mxd[v]);
}

void val(int *d, int *mxd, int *vv, int u, int f, int x) {
	if (!h[u])
		vv[u] = (int)(mxd[u] - d[u] >= x);
//	if (x == 7)
//		cout << u << ' ' << mxd[u] << ' ' << d[u] << '\n';
	for (int v : T[u])
		if (v != f)
			if (h[v])
				val(d, mxd, vv, v, u, x);
			else
				val(d, mxd, vv, v, u, x), vv[u] += vv[v];
}

bool chk(int x) {
	for (int i = 1; i <= n; i++)
		vL[i] = vR[i] = 0;
	val(dL, mxdL, vL, L, 0, x), val(dR, mxdR, vR, R, 0, x);
	int s = faR[L], t = faL[R], K = k - 2, mxL = 0, mxR = 0, f = 1;
	while (dL[s] < dL[t]) {
		K -= 2 + vL[s] + vR[t]; //cout << vL[s] << ' ' << vR[t] << ' ' << K << '\n';
		s = faR[s], t = faL[t];
	} if (s == t)
		if (vL[s])
			K -= 1 + vL[s], f = 0;
		else
			mxL = mxR = mxdL[s] - dL[s];
	s = faL[s], t = faR[t];
	while (f && s != L) {
		mxL = max(mxL + 1, mxdL[s] - dL[s]);
		if (mxL > x)
			break; 
		K++; s = faL[s];
	} while (f && t != R) {
		mxR = max(mxR + 1, mxdR[t] - dR[t]);
		if (mxR > x)
			break; 
		K++; t = faR[t];
	} int l = L, r = R; mxL = mxR = 0;
	while (l != s) {
		mxL = max(mxL + 1, mxdR[l] - dR[l]);
		if (mxL > x)
			break; 
		K++; l = faR[l];
	} while (r != t) {
		mxR = max(mxR + 1, mxdL[r] - dL[r]);
		if (mxR > x)
			break;
		K++; r = faL[r];
	} return K >= 0;
}

void solve() {
	n = read(), k = read();
	for (int i = 1, u, v; i < n; i++)
		u = read(), v = read(), T[u].push_back(v), T[v].push_back(u);
	if (k == n)
		return printf("0\n"), void();
	dfs(faL, dL, 1, 0); L = R = 1;
	for (int i = 1; i <= n; i++)
		if (dL[i] > dL[L])
			L = i;
	dfs(faL, dL, L, 0);
	for (int i = 1; i <= n; i++)
		if (dL[i] > dL[R])
			R = i;
	dfs(faR, dR, R, 0);
	h[R] = 1, ah(L, 0); mx(dL, mxdL, L, 0), mx(dR, mxdR, R, 0); 
	int l = 1, r = n; 
	while (l < r) {
		int mid = l + r >> 1;
		if (chk(mid))
			r = mid;
		else
			l = mid + 1;
	} printf("%d\n", l);
	for (int i = 1; i <= n; i++)
		T[i].clear(), dL[i] = dR[i] = mxdL[i] = mxdR[i] = vL[i] = vR[i] = 0;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int C = read(), T = read();
	while (T--) 
		solve();
	return 0;
}
