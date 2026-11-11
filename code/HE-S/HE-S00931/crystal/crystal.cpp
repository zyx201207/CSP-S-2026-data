#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, m;
int a[N], sum[N];
bool cmp (int a, int b) {return a > b;}

bool check (int num)
{
	for (int i = 1; i <= n; i++)
	{
		int L = 1, R = i;
		while (L < R)
		{
			int M = L + R >> 1; 
			int nd = (i - M + 1) * a[i] - (sum[i] - sum[M - 1]);
			if (nd <= m) R = M;
			else L = M + 1;  
		}
		if (i - L + 1 >= num) return 1;
	}
	return 0;
}

signed main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int L = 1, R = n;
	while (L < R)
	{
		int M = L + R + 1 >> 1;
		if (check(M)) L = M;
		else R = M - 1;
	}
	cout << L;
	return 0;
}
