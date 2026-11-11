#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 5005;
using ll = long long;
ll a[2000005];
ll dp[N][N], f[N][N];
class sgt
{
	pair<ll, ll> tree[N << 2];
	int lson(int id)
	{
		return id << 1;
	}
	int rson(int id)
	{
		return (id << 1) | 1;
	}
	pair<ll, ll> push_up(pair<ll, ll> x, pair<ll, ll> y)
	{
		if(x.first < y.first)
			return x;
		if(x.first > y.first)
			return y;
		return make_pair(x.first, x.second + y.second);
	}
public:
	void update(int id, int pl, int pr, int x, ll d, ll val)
	{
		if(pl == pr)
		{
			tree[id] = make_pair(d, val);
			return;
		}
		int mid = pl + pr >> 1;
		if(x <= mid)
			update(lson(id), pl, mid, x, d, val);
		else
			update(rson(id), mid+1, pr, x, d, val);
		tree[id] = push_up(tree[lson(id)], tree[rson(id)]);
	}
	pair<ll, ll> query(int id, int pl, int pr, int x, int y)
	{
		if(x <= pl && pr <= y)
		{
			return tree[id];
		}
		int mid = pl + pr >> 1;
		if(x > mid)
			return query(rson(id), mid+1, pr, x, y);
		if(y <= mid)
			return query(lson(id), pl, mid, x, y);
		return push_up(query(lson(id), pl, mid, x, y), query(rson(id), mid+1, pr, x, y));
	}
}T;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c, t, n, d, i, j, x, ans;
	pair<ll, ll> temp;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(i = 1; i <= n; i++)
			cin >> a[i];
		if(c <= 10)
		{
			ans = 0;
			for(i = 1; i <= n; i++)
			{
				dp[i][i] = 0;
				f[i][i] = 1;
				T.update(1, 1, n, i, 0, 1);
				for(j = i+1; j <= n; j++)
				{
					x = lower_bound(a+i, a+j+1, a[j] - d) - a;
					if(x == j)
					{
						break;
					}
					temp = T.query(1, 1, n, x, j-1);
					dp[i][j] = temp.first + 1;
					f[i][j] = temp.second;
					T.update(1, 1, n, j, dp[i][j], f[i][j]);
					if(f[i][j] == 2)
					{
						ans++;
					}
				}
			}
			cout << ans << "\n";
		}
		else if(c <= 12)
		{
			x = a[2] - a[1];
			d = d / x * x;
			if(d == 0 || d == x)
				cout << "0\n";
			else
				cout << max(0ll, n - 2 * (d / x) + 1) << "\n";
		}
	}
	return 0;
}
