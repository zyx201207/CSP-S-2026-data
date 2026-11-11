#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,a[N],m,ans = LLONG_MIN,maxn,sum;
void dfs(int num,int cnt,int ands,bool fir)
{
	if (num > n)
	{
		if (cnt == m)
		{
			ans = max(ands,ans);
		}
		return;
	}
	if (fir)
	{
		dfs(num + 1,cnt + 1,a[num],0);
		dfs(num + 1,cnt,ands,1);
	}
	else
	{
		dfs(num + 1,cnt + 1,ands & a[num],0);
		dfs(num + 1,cnt,ands,0);
	}
} 
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	sum = a[1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i != 1)
		{
			sum &= a[i];
		}
		maxn = max(maxn,a[i]);
	}
	if (m == 1)
	{
		cout << maxn;
		return 0;
	}
	if (m == n)
	{
		cout << sum;
		return 0;
	}
	dfs(1,0,0,1);
	cout << ans;
	return 0;
}

