#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
constexpr int N = 2e5 + 5, mod = 998244353;
template<typename Info>
struct SGT
{
	#define ls p << 1
	#define rs p << 1 | 1
	const int n;
	vector<Info> info;
	void push_up(int p)
	{
		info[p] = info[ls] + info[rs];
	}
	SGT(int _n) : n(_n), info(_n << 2) {};
	void modify(int p, int l, int r, int x, const Info &t)
	{
		if (l == r)
		{
			info[p] = t;
			return ;
		}
		int mid = l + r >> 1;
		if (x <= mid) modify(ls, l, mid, x, t);
		else modify(rs, mid + 1, r, x, t);
		push_up(p);
	}
	void modify(int x, const Info &t)
	{
		modify(1, 1, n, x, t);	
	}
	Info query(int p, int l, int r, int x, int y)
	{
		if (x <= l && r <= y) return info[p];
		int mid = l + r >> 1;
		if (y <= mid) return query(ls, l, mid, x, y);
		else if (x > mid) return query(rs, mid + 1, r, x, y);
		else return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
	}
	Info query(int x, int y)
	{
		return query(1, 1, n, x, y);
	}
	#undef ls
	#undef rs
};
struct Info
{
	int val;
	i64 cnt;
	Info(int _val = 0, i64 _cnt = 0) : val(_val), cnt(_cnt) {}
	friend Info operator+(const Info &a, const Info &b)
	{
		Info res;
		res.val = min(a.val, b.val);
		if (res.val == a.val) res.cnt += a.cnt;
		if (res.val == b.val) res.cnt += b.cnt;
		return res;
	} 
};
void solve()
{
	i64 n, d;
	cin >> n >> d;
	vector<i64> x(n + 1);
	for (int i = 1; i <= n; i++) cin >> x[i];
	i64 ans = 0;
	for (int l = 1; l <= n; l++)
	{
		int base = l - 1;
		SGT<Info> sgt(n - base);
		sgt.modify(l - base, Info(0, 1));
		for (int r = l + 1, j = l; r <= n; r++)
		{
			while (j < r && x[j] < x[r] - d) j++;
			if (j < r)
			{
				auto it = sgt.query(j - base, r - 1 - base);
				int dp = it.val;
				i64 cnt = it.cnt;
				if (cnt == 2) ans++;
				sgt.modify(r - base, Info(dp + 1, cnt));
			}
			else
			{
				sgt.modify(r - base, Info(1e9, 0));
			}
		}
	}
	cout << ans << "\n";
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
