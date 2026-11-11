#include <bits/stdc++.h>
#define int long long
using namespace std;

int n , m , ans , ans2 ,  ans3;
int a[200005];

void dfs(int u , int cnt , int sum)
{
	if(u > n)
	{
		return ;
	}
	if(cnt == m)
	{
		ans = max(ans , sum);
		return ;
	}
	dfs(u + 1 , cnt , sum);
	dfs(u + 1 , cnt + 1 , (sum & a[u + 1]));
}

signed main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		ans3 = max(ans3 , a[i]);
	}
	if(m == n)
	{
		ans2 = a[1];
		for(int i = 2;i <= n;i ++)
		{
			ans2 &= a[i];
		}
		cout << ans2;
	}
	else if(m == 1)
	{
		cout << ans3;
	}
	else
	{
		for(int i = 1;i <= n;i ++)
		{
			dfs(i , 1 , a[i]);
		}
		cout << ans;
	}
	return 0;
}

