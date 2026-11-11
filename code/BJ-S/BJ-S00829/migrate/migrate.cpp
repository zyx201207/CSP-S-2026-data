#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##KON = (r); i <= i##KON; ++i)
#define per(i, l, r) for(int i = (l), i##KON = (r); i >= i##KON; --i)
using namespace std;
using ll = long long;
constexpr ll N{2000005}, inf{0x3f3f3f3f3f3f3f3f};
ll tid, T, n, d, x[N], l[N], r[N];
namespace c2
// count dis(i, j) = 2 && cnt(i, j) = 2
// l[l[i]] <= j < l[i] && r[j] = l[i] + 1
{
	struct cone
	{
		ll cnt[N], p;
		void init()
		{
			p = 0;
			rep(i, 1, n)
				cnt[i] = 0;
		}
		ll qry(int x, int y)
		{
			// ll ans=0;rep(i,1,x)ans+=r[i]==y;return ans;
			assert(p<=x);
			for(; p < x; ++cnt[r[++p]]);
			return cnt[y];
		}
	} c[2];
	ll main()
	{//return 0;
		c[0].init(), c[1].init();
		ll ans = 0;
		rep(i, 1, n)
			ans += c[1].qry(l[i] - 1, l[i] + 1) - c[0].qry(l[l[i]] - 1, l[i] + 1);
		return ans;
	}
}
namespace c3
// count dis(i, j) > 2 && cnt(i, j) = 2
{
	ll f[N], g[N];
	ll main()
	{
		// return 0;
		rep(i, 1, n)
			f[i] = g[i] = 0;
		rep(i, 1, n) if(r[i] > i)
			++f[r[i]];
		rep(i, 1, n) if(l[i] < i && r[l[i]] == i)
			f[i] += f[l[i]];
		rep(i, 1, n) if(l[i] < i)
			++g[l[i]];
		per(i, n, 1) if(r[i] > i && l[r[i]] == i)
			g[i] += g[r[i]];
		ll ans = 0;
		rep(i, 1, n) if(l[l[i]] < l[i] && r[l[l[i]]] == l[i] + 1 && r[r[l[l[i]]]] == i)
			ans += f[l[l[i]]] * g[i]; // Part I: all included, enumerate rpoint
		rep(i, 1, n) if(l[l[i]] < l[i] && r[l[l[i]]] == l[i] + 1 && r[r[l[l[i]]]] >= i) // cout<<i<<endl,
			ans += f[l[l[i]]]; // Part II: rpoint is same
		rep(i, 1, n) if(r[r[i]] > r[i] && l[r[r[i]]] == r[i] - 1 && l[l[r[r[i]]]] <= i)
			ans += g[r[r[i]]]; // Part III: lpoint is same
		return ans;
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(cin >> tid >> T; T--;)
	{
		cin >> n >> d;
		rep(i, 1, n)
			cin >> x[i];
		l[1] = 1, r[n] = n;
		rep(i, 2, n) for(l[i] = l[i - 1]; x[i] - x[l[i]] > d; ++l[i]);
		per(i, n - 1, 1) for(r[i] = r[i + 1]; x[r[i]] - x[i] > d; --r[i]);
		// cout<<"L: ";rep(i,1,n)cout<<l[i]<<" \n"[i==n];
		// cout<<"R: ";rep(i,1,n)cout<<r[i]<<" \n"[i==n];
		cout << c2::main() + c3::main() << "\n";
	}
	return 0;
}