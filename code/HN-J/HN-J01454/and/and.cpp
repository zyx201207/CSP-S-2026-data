#include<bits/stdc++.h>
#define pre(i, l, r)	for(int i = (l); i <= (r); ++i)
#define fpre(i, r, l)	for(int i = (r); i >= (l); --i)
#define ll long long

using namespace std;

const int maxn = 2e5 + 5;
const int inf = 1e9;
const ll lnf = 2e18;

int n, m;
ll a[maxn];
int c[2];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	pre(i, 1, n)
		scanf("%lld", &a[i]);
	vector<int> v;
	pre(i, 1, n)
		v.emplace_back(i);
	ll ans = 0;
	fpre(i, 30, 0)
	{
		memset(c, 0, sizeof c);
		for(auto y : v)
			c[a[y] >> i & 1]++;
		if(c[1] >= m)
		{
			vector<int> g;
			for(auto y : v)
				if(a[y] >> i & 1)
					g.emplace_back(y);
			v.swap(g);
			ans += (1LL << i);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
