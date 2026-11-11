#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500005
#define M 300005
#define fr(i, l, r) for(ll i = l; i <= r; i++)
#define mem(a, b) memset(a, b, sizeof(a))
#define relx(a, b) (a) = max(a, b)
ll a[N];
ll f[N], mq[N];
//f[i]是i号节点产生的子问题位置 
ll ans[M], lst[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	fr(i, 1, n)
	{
		cin >> a[i];
		mq[i] = 1;
	}
	for(ll i = n; i >= 1; i--)
	{
		if(lst[a[i]])
		{
			f[i] = lst[a[i]] + 1;
		}
		else
		{
			f[i] = i + 1;
		} //如果有边界自动设为滚木值(n + 1) 
		relx(lst[a[i]], i);
//		cout << f[i] << ' ';
	}
//	cout << '\n';
	fr(i, 1, n)
	{
		mq[f[i]] += mq[i];
		ans[a[i]] += mq[i];
//		cout << mq[i] << ' ';
	}
//	cout << '\n';
	bool fst = false;
	fr(i, 1, m)
	{
		if(fst)cout << ' ';
		cout << ans[i];
		fst = true;
	}
	return 0;
}
//fc card.out card.ans
