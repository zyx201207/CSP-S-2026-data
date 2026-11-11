#include <bits/stdc++.h>
#define int long long

using namespace std;

bool BEGIN;

int n, m;
int a[500010];
int b[500010], c[5000010], idx;
int q[500010], hd, tl = 1;
int ans = 1;
bool END;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	cerr << "memory: " << (int)(&END - &BEGIN) / 1024 / 1024 << " MB\n";
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + n + 1);
//	b[idx = 1] = a[1];
//	c[1] = 1;
//	for(int i = 2;i <= n;i ++)
//	{
//		if(a[i] != a[i - 1]) b[++ idx] = a[i];
//		c[idx] ++;
//	}
	int sum = 0;
	q[++ hd] = a[1];
	for(int i = 2;i <= n;i ++)
	{
		sum += (hd - tl + 1) * (a[i] - a[i - 1]);
		while(sum > m) sum -= (a[i] - q[tl]), tl ++;
//		for(int j = 1;j <= c[i];j ++) q[++ hd] = b[i];
		q[++ hd] = a[i];
//		cerr << hd << " " << tl << "\n";
		ans = max(ans, hd - tl + 1);
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
