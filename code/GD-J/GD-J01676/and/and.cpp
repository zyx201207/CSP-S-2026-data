#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,m,a[maxn],ans = INT_MIN,cnt = 0;
int c[maxn];
vector<int> v;
void dfs(int k,int num)
{
	if (k == m + 1)
	{
		ans = max(ans,num);
		cnt++;
		return ;
	}
	if (cnt >= 300000000)
	{
		cout << ans;
		exit(0);
	}
	for (int i = c[k - 1] + 1;i <= n - (m - k);i++)
	{
		if (a[i] == 0) continue;
		c[k] = i;
		dfs(k + 1,num & a[i]);
	}
	return ;
}
bool che(int num)
{
	return (num & (num + 1) == 0);
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool f = true;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (!che(a[i] + 1)) f = false;
	}
	if (f)
	{
		sort(a + 1,a + n + 1);
		cout << a[n - m + 1];
		return 0;
	}
	dfs(1,INT_MAX);
	cout << ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
