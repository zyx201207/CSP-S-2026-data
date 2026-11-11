#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
const int maxm = 2e5 + 100;

int bit[maxn];
int a[maxm];
bool flag[maxn], flaga = 1;
int n, m, maxx;
int cntmaxx;

bool cmp(int x, int y)
{
	return x > y;
}

//void work(long long tmp)
//{
//	int cnt = 0;
//	long long tmp2 = tmp;
//	while (tmp)
//	{
//		tmp = tmp >> 1;
//		cnt ++;
//	}
//	
//	for (int i = 1; i <= cnt; ++i)
//	{
//		bit[i] += (tmp2 % 2);
//		tmp2 = tmp2 >> 1;
//	}
//}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	
//	for (int i = 1; i <= n; ++i)
//	{
//		int x;
//		cin >> x;
//		a[i] = x;
//		if (x != i - 1) flaga = 0;
//		maxx = max(maxx, x);
//		work(x);
//	}
	
	sort(a + 1, a + n + 1, cmp);
	int ans = a[1];
	for (int i = 1; i <= m; ++i)
	{
		ans &= a[i];
	}
	cout << ans << "\n";
	return 0;
	
	
//	while (maxx)
//	{
//		maxx = maxx >> 1;
//		cntmaxx ++;
//	}
	
}
