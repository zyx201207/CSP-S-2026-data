#include <bits/stdc++.h>
#define gc getchar
#define N 500001
using namespace std;

inline int read()
{
	int x = 0;
	char ch = gc();
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = gc();
	}
	return x;
}

int a[N];
char c[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n = read();
	for (int i = 1;i <= n;i++)
	{
		a[i] = read();
		c[i] = gc();
	}
	int l = 1, r = n;
	long long ans = 0;
	while(l <= r)
	{
		if(c[l] == c[r])
		{
			int minn = min(a[l], a[r]);
			a[l] -= minn;
			a[r] -= minn;
		}
		else
		{
			int minn = min(a[l], a[r]);
			ans += minn;
			a[l] -= minn;
			a[r] -= minn;
		}
		if(a[l] <= 0) l++;
		if(a[r] <= 0) r--;
	}
	cout << ans << endl;
	return 0;
}
