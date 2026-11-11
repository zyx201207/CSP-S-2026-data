#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int a[N];
int n , m;
int maxn = 0;
void dfs(int step , int cnt , int ans , bool flag)
{
	if (step > n)
	{
		if (cnt == m) maxn = max(maxn , ans);
		return ;
	}
	if (cnt == m)
	{
		maxn = max(maxn , ans);
		return ;
	}
	if (flag == 0) dfs(step + 1 , cnt + 1 , a[step] , 1);
	else dfs(step + 1 , cnt + 1 , (ans & a[step]) , flag);
	dfs(step + 1 , cnt , ans , flag);
}
signed main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (m == n)
	{
		int res = a[1];
		for (int i = 2; i <= n; i++) res = (res & a[i]);
		cout << res;
		return 0;
	}
	if (m == 1)
	{
		int maxx = 0;
		for (int i = 1; i <= n; i++) maxx = max(maxx , a[i]);
		cout << maxx;
		return 0;
	}
	if (m == 2)
	{
		int maxa = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				maxa = max(maxa , (a[i] & a[j]));
			}
		}
		cout << maxa;
		return 0;
	}
	if (n <= 20)
	{
		dfs(1 , 0 , 0 , 0);
		cout << maxn;
		return 0;
	}
	return 0;
}

