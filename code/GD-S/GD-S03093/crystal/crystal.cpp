#include <iostream>
#include <cstdio>
#include <algorithm>
//#include <queue>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, ans;
ll m, x[N], sum[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> x[1] >> x[2];
	bool A = true;
	for (int i = 3; i <= n; i++)
	{
		cin >> x[i];
		if (x[i]-x[i-1] != x[i-1]-x[i-2])
			A = false;
	}
	if (A)
	{
		ll d = x[2]-x[1];
		for (int i = 1; i <= n; i++)
		{
			sum[i] = sum[i-1] + i - 1;
		}
		for (int i = 1; i <= n; i++)
			sum[i] *= d;
		auto t = lower_bound(sum+1, sum+n+1, m)-sum;
		if (t > n) t = n;
		if (sum[t] > m) t--;
		cout << t;
		return 0;
	}
	sort(x+1, x+n+1);
	for (int i = 1; i <= n; i++)
	{
		ll temp = 0;
		int num = 1;
		for (int j = i-1; j >= 1; j--)
		{
			if (temp + x[i] - x[j] > m) break;
			num++;
			temp += x[i]-x[j];
		}
		ans = max(ans, num);
	}
	cout << ans;
	return 0;
}

/*

5 5
1 2 4 8 9



5 8
-3 -1 2 2 7




*/
