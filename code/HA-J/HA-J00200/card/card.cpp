#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[500005], last[300005], dp[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		last[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		dp[a[i]] += 1 + (last[a[i - 1]] == i - 1 ? dp[a[i - 1]] : 0);
	}
	for(int i = 1; i <= m; i++)
	{
		cout << dp[i];
		if(i != m)cout << ' ';
	}
	return 0;
}

