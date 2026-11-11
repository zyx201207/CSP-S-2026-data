#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define pb push_back

constexpr ll N = 5000;

ll x[N + 10];
ll tmp[N + 10];

struct node
{
	ll minn, way;
} tr[4 * N + 10];

void pushup(ll u)
{
	ll ls = u << 1, rs = u << 1 | 1;
	if (tr[ls].minn == tr[rs].minn)
	{
		tr[u].minn = tr[ls].minn;
		tr[u].way = tr[ls].way + tr[rs].way;
	}
	else if (tr[ls].minn < tr[rs].minn)
	{
		tr[u].minn = tr[ls].minn;
		tr[u].way = tr[ls].way;
	}
	else
	{
		tr[u].minn = tr[rs].minn;
		tr[u].way = tr[rs].way;
	}
}

void modify(ll u, ll l, ll r, ll pos, ll val, ll way)
{
	if (l == r)
	{
		tr[u] = {val, way};
		return ;
	}
	ll mid = (l + r) >> 1, ls = u << 1, rs = u << 1 | 1;
	if (pos <= mid)
	{
		modify(ls, l, mid, pos, val, way);
	}
	else
	{
		modify(rs, mid + 1, r, pos, val, way);
	}
	pushup(u);
}

node query(ll u, ll l, ll r, ll ql, ll qr)
{
	if (ql > qr)
	{
		return {INF, 0};
	}
	if (ql <= l && r <= qr)
	{
		return tr[u];
	}
	ll mid = (l + r) >> 1, ls = u << 1, rs = u << 1 | 1;
	node ans = {INF, 0};
	if (ql <= mid)
	{
		node lans = query(ls, l, mid, ql, qr);
		if (lans.minn < ans.minn)
		{
			ans.minn = lans.minn;
			ans.way = lans.way;
		}
		else if (lans.minn == ans.minn)
		{
			ans.way += lans.way;
		}
	}
	if (qr >= mid + 1)
	{
		node rans = query(rs, mid + 1, r, ql, qr);
		if (rans.minn < ans.minn)
		{
			ans.minn = rans.minn;
			ans.way = rans.way;
		}
		else if (rans.minn == ans.minn)
		{
			ans.way += rans.way;
		}
	}
	return ans;
}

void solve()
{
	ll n, d;
	cin >> n >> d;
	for (ll i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
	{
		ll l = 1, r = i, res = -1;
		while (l <= r)
		{
			ll mid = l + (r - l) / 2;
			if (llabs(x[mid] - x[i]) <= d)
			{
				res = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		tmp[i] = res;
	}
	for (ll l = 1; l <= n; l++)
	{
		memset(tr, 0, sizeof(tr));
		modify(1, 1, n, l, 0, 1);
//		cout << "ok: " << l << endl;
		for (ll jjj = l + 1; jjj <= n; jjj++)
		{
			node res = query(1, 1, n, tmp[jjj], jjj - 1);
//			cout << res.minn << " " << res.way << endl;
			if (res.way == 2)
			{
				ans++;
			}
			modify(1, 1, n, jjj, res.minn + 1, res.way);
		}
	}
	cout << ans << "\n";
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c, t;
	cin >> c >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

// 18:06 Ð´Íê±©Á¦

