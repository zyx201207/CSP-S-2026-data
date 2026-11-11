#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 5e5 + 5;
int n;
ll m;
ll a[N];
ll sum[N];
int ans = 0;
bool check(int l, int r)
{
	//sum[r]-sum[l-1]
	//a[r]
	ll diff = a[r] * (r - l + 1) - (sum[r] - sum[l - 1]);
	return diff <= m;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (check(mid, i)) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << "\n";
	return 0;
}


