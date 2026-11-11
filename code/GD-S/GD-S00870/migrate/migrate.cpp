#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// we want find the minimal double routed islands?
// or is that enough?
// for any path from u, the path length is always non-decreasing
// the number of shortest paths is also non-decreasing?
// no, we can hack this with [1, 1, 1, 1, 1, 2, 3, 4, 5] (reachability)
// if this is true, then we can basically stop after reaching 3
// therefore I think we can just grab all the maximal extension
// to find min dist
// this part can be done for any pair (u, v)
// in O(logn) time

// also we can solve this problem in O(n^3) with typical dp
// can be optimized to O(n^2logn) with segment tree
// can be optimized to O(n^2) with monotonic queue (40pts)

// the exactly part is really annoying

// let's see what the dual path might look like
// I think they only diverge once at the exact same part
// in the diverging part
// the paths need to be completely different
// otherwise we have
// [ same ][ path1 ]u[ path2 ][same]
// [ same ][ path3 ]u[ path4 ][same]
// but we can swap the minimal parts, and it will no longer be dual
// the path count exceeds 2
// the divergent section must also be unique
// otherwise, we can also exchange

// we can produce the unique sections first
// what characterizes these unique sections?
// hypothesis: they always go on maximal jumps
// obviously, maximal jumps guarentee uniqueness
// false: [1, 1, 2, 2] (1, 3)

// what if the correct method is dp?
// cdq + dp?

// we can construct 2 paths always
// one jumping maximally from the left, the other from the right
// these 2 sequences represents min/max indicies for any sequence
// any valid sequence's index must be between them
// if any 2 sequences exist, this will definitely generate them
// hypothesis: if there exist any l[i] < v[i] < r[i] in the generated sequence
// then there must be another valid sequence
// I think this is true
// we can just increamentally increase the positions before, until we can reach v
// but this this guarentee only 2?
// I don't think so
// actually, can we have a divergent sectiona longer than 1?
// I don't think so
// after jumping 1 step, we always have the option to merge right back
// the creats multiple sequences

// if we take out all the left / right maximal jumps
// it will form a tree
// the left tree forms a min heap, right forms a max heap

// so we need to count [same]u/v[same]
// u and v have to be consecutive
// otherwise you may adjust
// and [same] means that the island u/v jumps to is the same
// and the last island in [same] must be able (and only able) to jump to u/v
// we can find the maximal [sam] extentions for left and right
// any affix will also be valid

int n;
ll d, a[2000010];
int prv[2000010], nxt[20000100];
int x[2000010], y[2000010];
int l[2000010], r[2000010];

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, j = 1; i <= n; i++) {
		while (j < i && a[i] - a[j] > d) j++;
		prv[i] = j;
	}
	for (int i = n, j = n; i >= 1; i--) {
		while (j > i && a[j] - a[i] > d) j--;
		nxt[i] = j;
	}
	for (int i = 1, j = 1; i <= n; i++) {
		while (j < n && nxt[j] <= i) j++;
		x[i] = j;
		l[i] = max(j - prv[i], 0) + 1;
		if (nxt[prv[i]] == i) l[i] += l[prv[i]];
	}
	for (int i = n, j = n; i >= 1; i--) {
		while (j > 1 && prv[j] >= i) j--;
		y[i] = j;
		r[i] = max(nxt[i] - j, 0) + 1;
		if (prv[nxt[i]] == i) r[i] += r[nxt[i]];
	}
	ll ans = 0;
	for (int i = 2; i + 2 <= n; i++) {
		if (prv[i] != prv[i + 1] || nxt[i] != nxt[i + 1]) continue;
		int u = prv[i], v = nxt[i + 1];
		if (nxt[u] != i + 1 || prv[v] != i) continue;
		ans += (l[u] - 1) * (r[v] - 1);
	}
	for (int i = 2; i + 2 <= n; i++) {
		int d1 = x[i] == 1, d2 = y[i + 1] == n;
		ans += 1ll * (x[i] - prv[i] + d1) * (nxt[i + 1] - y[i + 1] + d2);
	}
	cout << ans << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	
	return 0;
}
