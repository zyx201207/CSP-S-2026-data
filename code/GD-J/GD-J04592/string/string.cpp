#include<bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
long long n, tar, j, cur, cnt, nw, us, lst, gd, tim, a[maxn], b[maxn], ra[maxn];
char c[maxn], rc[maxn];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	//j = n;
	nw = 1;
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i] >> c[i];
		tar += a[i];
	}
	int i = n;
	//cout << tar << '\n';
	while (gd < tar)
	{
		++ tim;
		if (a[i] < a[nw])
		{
			//cnt += a[i];
			if (c[i] != c[nw])
			{
				us += a[i];
			}
			gd += 2 * a[i];
			a[nw] -= a[i];
			//cout << "a" << '\n';
		}
		else
		{
			if (c[i] != c[nw])
			{
				//cout << cnt << " " << a[nw];
				us += a[nw];
			}
			gd += (a[nw]) * 2;
			a[i] -= a[nw];
			
			cnt = 0;
			++ nw;
			++ i;
			//cout << gd << '\n';
		}
		-- i;
		//cout << i << " " << nw << " " << us << " " << gd << " " << a[1] << " " << a[2] << " " << a[3] << '\n';
		//cout << tim << '\n';
	}
	cout << us;
	return 0;
}
