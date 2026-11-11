#include <bits/stdc++.h>
// #define int ll
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
// bool __st__;
int n;
ll d;
ll a[N];
int mem[2][N];
int toR(int idx)
{
	if (~mem[0][idx]) return mem[0][idx];
	int l = idx + 1, r = n, ans = idx;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] - a[idx] <= d) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return mem[0][idx] = ans;
}
int toL(int idx)
{
	if (~mem[1][idx]) return mem[1][idx];
	int l = 1, r = idx - 1, ans = idx;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[idx] - a[mid] <= d) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return mem[1][idx] = ans;
}
int extL[N], extR[N];
void solve()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		extL[i] = extR[i] = 0, mem[0][i] = mem[1][i] = -1;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	// first, deal extL and extR
	extL[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int hereTo = toL(i), nxtTo = min(i, (i == n ? n : toL(i + 1)));
		extL[i] = nxtTo - hereTo + (hereTo != nxtTo ? extL[hereTo] : 0);
	}
	extR[n] = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		int hereTo = toR(i), nxtTo = max(i, (i == 1 ? 1 : toR(i - 1)));
		extR[i] = hereTo - nxtTo + (hereTo != nxtTo ? extR[hereTo] : 0);
	}
	// then enum (i, i + 1)
	ll ans = 0;
	for (int i = 2; i + 1 < n; i++)
	{
		if (a[i + 1] - a[i] > d) continue;
		int u = i, v = i + 1;
		int uR = toR(u), vL = toL(v);
		int nuR = toR(u - 1), nvL = toL(v + 1);
		if (uR <= v || vL >= u) continue;
		if (nuR >= uR || nvL <= vL) continue;
		ll fromL = (toL(u) < vL ? 1 : extL[vL] + 1);
		ll fromR = (toR(v) > uR ? 1 : extR[uR] + 1);
		ans += (fromR + (uR - nuR - 1)) * (fromL + (nvL - vL - 1));
	}
	cout << ans << '\n';
}
// bool __ed__;
// void PrintMem() { cerr << (&__st__ - &__ed__) / 1048576.0 << '\n'; }
signed main()
{
	// PrintMem();
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	// clock_t st = clock();
	int c, T;
	cin >> c >> T;
	while (T--)
		solve();
	// cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << '\n';
	return 0;
}
/*
m=1不存在
m=2中间点一定相邻
m>2一定由m=2向左向右扩展得来
所以先处理向左向右的，再枚举相邻点
每一次扩展只有反向第一个到不了，这个到得了的那段区间能够作为端点，但是扩展只有最远的那一个点可以扩展
17:05
好多细节，调了好久
有时间记得回来写一个快读
*/