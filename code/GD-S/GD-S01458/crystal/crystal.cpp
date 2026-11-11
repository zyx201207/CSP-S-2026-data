#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans = 1;
vector<int> vec;
signed main()
{
	cin.tie(0)->ios::sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	vec.assign(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= n; i++)
	{
		int k = m, j = i - 1, sum = 0;
		while (j >= 1 && k - (vec[i] - vec[j]) >= 0)
			k -= vec[j], sum++, j--;
		//		cout<<sum+1<<" ";
		ans = max(ans, sum + 1);
	}
	cout << ans;
	return 0;
}
