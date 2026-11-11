#include <bits/stdc++.h>

#define x first
#define y second
#define int long long

using namespace std;

const int N = 1e6 + 10;
const int M = 5010;

int c, T;
int n, d;
int x[N], f[N];
struct node
{
	int l, r;
	int min_, cnt;
}tr[N << 2];
pair<int, int> dist[M];

void pushup(int u)
{
	if(tr[u << 1].min_ == tr[u << 1 | 1].min_)
	{
		tr[u].min_ = tr[u << 1].min_;
		tr[u].cnt  = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
	}else if(tr[u << 1].min_ > tr[u << 1 | 1].min_)
	{
		tr[u].min_ = tr[u << 1 | 1].min_;
		tr[u].cnt  = tr[u << 1 | 1].cnt ;
	}else{
		tr[u].min_ = tr[u << 1].min_;
		tr[u].cnt  = tr[u << 1].cnt ; 
	}
}

void build(int u, int l, int r)
{
	int mid = l + r >> 1;
	tr[u].l = l, tr[u].r = r;
	if(l == r)
	{
		tr[u].min_ = 1e18 + 1;
		tr[u].cnt  = 1;
		return;
	}
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void modify(int u, int l, int r, int x, int c, int cnt)
{
	if(l == r)
	{
		tr[u].min_ = c;
		tr[u].cnt  = cnt;
		return;
	}
	int mid = l + r >> 1;
	if(x <= mid) modify(u << 1, l, mid, x, c, cnt);
	else modify(u << 1 | 1, mid + 1, r, x, c, cnt);
	pushup(u);	
}

pair<int, int> work(pair<int, int> a, pair<int, int> b)
{
	if(a.x == b.x) return make_pair(a.x, a.y + b.y);
	if(a.x > b.x) return b;
	return a;
}

pair<int, int> query(int u, int l, int r, int L, int R)
{
	if(L <= l && r <= R) return make_pair(tr[u].min_, tr[u].cnt);
	int mid = l + r >> 1;
	pair<int, int> res = {1e18 + 1, 0};
	if(L <= mid) res = work(res, query(u << 1, l, mid, L, R));
	if(R > mid) res = work(res, query(u << 1 | 1, mid + 1, r, L, R));
	return res;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while(T -- )
	{
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++ ) cin >> x[i];
		if(n == 1)
		{
			cout << 0 << "\n";
			continue; 
		}
		x[0] = -1e18 - 1;
		x[n + 1] = 1e18 + 1;
		if(n <= 5000)
		{
			int ans = 0;
			for(int l = 1 ; l <= n ; l ++ )
			{
				build(1, l, n);
				dist[l] = {0, 1};
				modify(1, l, n, l, 0, 1);
				for(int r = l + 1 ; r <= n ; r ++ )
				{
					if(x[r] - x[r - 1] > d) continue;
					int L = l, R = r - 1;
					while(L < R)
					{
						int mid = L + R >> 1;
						if(x[r] - x[mid] > d) L = mid + 1;
						else R = mid;
					}
					dist[r] = query(1, l, n, L, r - 1);
					dist[r].x ++ ;
					modify(1, l, n, r, dist[r].x, dist[r].y);
					if(dist[r].y == 2) ans ++ ;
				}
			}
			cout << ans << "\n";
			continue;
		}
		if(c == 11 || c == 12)
		{
			int max_ = d / (x[2] - x[1]);
			if(max_ <= 1)
			{
				cout << 0 << "\n";
				continue; 
			}
			int len = 2 * max_;
			cout << max(0ll, n - len + 1) << "\n";
			continue;
		}
		
	}
	return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/
