#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 5e5+5;
using ll = long long;
ll a[N];
ll n, m;
class sgt
{
	struct node
	{
		ll sum, tag;
	}tree[N << 2];
	int lson(ll id)
	{
		return id << 1;
	}
	int rson(ll id)
	{
		return (id << 1) | 1;
	}
	void push_up(ll id)
	{
		tree[id].sum = tree[lson(id)].sum + tree[rson(id)].sum;
	}
	void addtag(ll id, ll pl, ll pr, ll d)
	{
		tree[id].sum += (pr - pl + 1) * d;
		tree[id].tag += d;
	}
	void push_down(ll id, ll pl, ll pr)
	{
		if(tree[id].tag == 0)
			return;
		int mid = pl + pr >> 1;
		addtag(lson(id), pl, mid, tree[id].tag);
		addtag(rson(id), mid+1, pr, tree[id].tag);
		tree[id].tag = 0;
	}
public:
	void update(ll id, ll pl, ll pr, ll x, ll y, ll d)
	{
		if(x <= pl && pr <= y)
		{
			addtag(id, pl, pr, d);
			return;
		}
		push_down(id, pl, pr);
		ll mid = pl + pr >> 1;
		if(x <= mid)
			update(lson(id), pl, mid, x, y, d);
		if(mid + 1 <= y)
			update(rson(id), mid+1, pr, x, y, d);
		push_up(id);
	}
	ll query(ll id, ll pl, ll pr, ll x, ll y)
	{
		if(x <= pl && pr <= y)
		{
			return tree[id].sum;
		}
		push_down(id, pl, pr);
		ll mid = pl + pr >> 1, res = 0;
		if(x <= mid)
			res += query(lson(id), pl, mid, x, y);
		if(mid + 1 <= y)
			res += query(rson(id), mid+1, pr, x, y);
		return res;
	}
}T;
ll binery(ll id)
{
	ll l, r, mid;
	l = 0, r = id+1;
	while(l + 1 < r)
	{
		mid = l + r >> 1;
		if(T.query(1, 1, n, mid, id) <= m)
			r = mid;
		else
			l = mid;
	}
	return r;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i, ans=1;
	cin >> n >> m;
	for(i = 1; i <= n ;i++)
		cin >> a[i];
	sort(a+1, a+1+n);
	for(i = 2; i <= n; i++)
	{
		T.update(1, 1, n, 1, i-1, a[i] - a[i-1]);
		ans = max(ans, i - binery(i) + 1);
	}
	cout << ans;
	return 0;
}
