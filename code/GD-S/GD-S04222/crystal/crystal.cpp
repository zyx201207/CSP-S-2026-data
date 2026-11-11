#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans;
ll m, a[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		int cur = i - 1, ans_ = 1, m_ = m;
		while(a[i] == a[i + 1]) i++, ans_++;
		while(cur >= 1 && abs(a[cur] - a[i]) <= m_)
		{
			ans_++;
			m_ -= a[cur];
			cur--;
		}
		ans = max(ans, ans_);
	}
	cout<<ans;
	return 0;
}
