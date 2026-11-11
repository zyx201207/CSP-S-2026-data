#include <bits/stdc++.h>
#define int long long
using namespace std;

bool ST;

const int N = 2e6 + 5;
int id, t; 

int n;
long long d, a[N], ans;
int fa[N], cnt[N];
int pre1[N], pre2[N];

int tree[N];
int lowbit (int x) { return x & (-x); }
void modify (int x, int y) { while (x <= n) { tree[x] += y; x += lowbit (x); } }
int query (int x) { if (x <= 0) return 0; int ret = 0; while (x) { ret += tree[x]; x -= lowbit (x); } return ret; }

void solve () {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	int now = 1;
	for (int i = 1; i <= n; ++i) {
		now = max (now, i);
		while (now < n && a[now + 1] - a[i] <= d) ++now;
		fa[i] = now;
	} 
	
	for (int i = 1; i <= n; ++i) {
		cnt[i] = 1;
		if (fa[fa[i]] == fa[i]) continue;
		int ff = fa[fa[i]], now = fa[i];
		for (int j = 20; j >= 0; --j) if (now - (1 << j) > i && fa[now - (1 << j)] == ff) now -= (1 << j);
		cnt[i] = fa[i] - now + 1;
	}
	
	int lst = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] - a[i - 1] > d) lst = i;
		pre1[i] = lst;
		if (cnt[i] != 1) lst = i;
	}
	lst = n + 1;
	for (int i = n; i >= 1; --i) {
		if (a[i + 1] - a[i] > d) lst = i;
		pre2[i] = lst;
		if (cnt[i] != 1) lst = i;
	}
	
	for (int i = 1; i <= n; ++i) if (cnt[i] == 1) modify (i, 1);
	for (int i = 1; i <= n; ++i) if (cnt[i] == 2) ans += 1LL * (query (i) - query (pre1[i]) + 1) * (query (pre2[fa[i]] - 1) - query (fa[i]));
	
	cout << ans << '\n';
}

void clear () {
	ans = 0;
	for (int i = 1; i <= n; ++i) a[i] = fa[i] = cnt[i] = pre1[i] = pre2[i] = 0;
	for (int i = 1; i <= n; ++i) tree[i] = 0;
}

bool ED;

signed main () {

	ios::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);

	cin >> id >> t;
	while (t--) {
		solve ();
		clear ();
	}
	
	return 0;
}


/*
15:19 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:20 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:21 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:22 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:23 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:24 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:25 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:26 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:27 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:28 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:29 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:30 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:31 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:32 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:33 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:34 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:35 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:36 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:37 正在咀嚼德芙包装让旁边的人感到害怕 (bushi)
15:38 正在咀嚼德芙包装让旁边的人感到害怕 (bushi) 
*/ 

