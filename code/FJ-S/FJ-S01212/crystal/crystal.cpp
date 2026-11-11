#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
long long n, m, a[N], l, r, mid, c[N], mx;
bool check(long long mid)
{
	for(int i = 1; i <= n; i++)
	{
		if(mid - a[i] < 0)
			c[i] = 1e18;
		else
			c[i] = mid - a[i];
	}
	sort(c + 1, c + n + 1);
	int cnt = 0, sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(sum + c[i] > m)
			break;
		else
		{
			cnt++;
			sum += c[i];
		}
	}
	if(cnt > mx and cnt <= m)
	{
//		cout << mid << ":" << cnt << endl;
		mx = max(mx, cnt * 1ll);
		return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		r = max(r, a[i]);
		l = min(l, a[i]);
	}
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << mx << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
