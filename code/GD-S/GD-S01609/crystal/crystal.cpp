#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 500005;
ll n, m;
struct code
{
	ll x, ans;
} a[N];

bool cmp1(const code &a, const code &b)
{
	return a.x < b.x;
}
bool cmp2(const code &a, const code &b)
{
	return a.ans > b.ans;
}

ll dfs(ll k)
{
	ll ans(1), temp(0), dm = m;
	temp = a[k].x;
	while (dm >= temp - a[k-1].x && k > 1)
	{
		ans++;
		dm -= temp - a[k-1].x;
		k--;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i].x;
	}
	sort(a+1, a+n+1, cmp1);
	
	for (ll i = 1; i <= n; i++)
	{
		a[i].ans = dfs(i);
	}
	sort(a+1, a+n+1, cmp2);
	cout << a[1].ans;
	return 0;
} 
