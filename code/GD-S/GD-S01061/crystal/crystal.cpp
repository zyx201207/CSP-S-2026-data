#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;//m=1e18
int n, m, a[N], c[N], maxn = INT_MIN, sum[N], f[N];//f[i]表示以a[i]为基准最多可以选几个合成 
deque<int> Q;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a+ n + 1);
	sum[1] = 0, f[1] = 1;
	for(int i = 2;i <= n;i ++)
	{
		f[i] = f[i - 1] + 1;
		Q.push_front(a[i]);
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * f[i - 1];
		while(sum[i] > m && !Q.empty())
		{
			sum[i] -= (a[i] - Q.back());
			Q.pop_back();
			f[i] --;
		}
	}
	for(int i = 1;i <= n;i ++)
	{
		maxn = max(maxn, f[i]);
	}
	cout << maxn << '\n';
	return 0;
}
