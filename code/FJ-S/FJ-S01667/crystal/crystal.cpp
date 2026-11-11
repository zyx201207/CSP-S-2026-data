#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define pb push_back

constexpr ll N = 5e5;

ll n, m;
ll a[N + 10];
ll sum[N + 10];

bool check(ll l, ll r)
{
	ll tot = a[r] * (r - l + 1);
	return sum[r] - sum[l - 1] + m >= tot;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	ll ans = 1;
	for (ll i = 1; i <= n; i++)
	{
		ll l = i, r = n, res = n;
		while (l <= r)
		{
			ll mid = l + (r - l) / 2;
			if (check(i, mid))
			{
				res = mid;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		ans = max(ans, res - i + 1);
	}
	cout << ans << "\n";
	return 0;
}

// 15:21 
// 先写了st，又写了线段树
// 然后发现排个序+二分就好了
// 不想写双指针是因为懒
// 发现居然缺省源忘记写 INF 了 

