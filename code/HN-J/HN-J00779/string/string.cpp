#include <bits/stdc++.h>
using namespace std;
long long a[200005], b[200005], sum, s;
string c[200005], d[200005];
int n, cnt;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		if(c[i] == c[i - 1])
		{
			b[cnt] += a[i];
		}
		else
		{
			cnt++;
			d[cnt] = c[i];
			b[cnt] = a[i];
		}
	}
	int e = cnt;
	if(cnt % 2 == 1)
	{
		cnt++;
	}
	for(int i = 1; i <= cnt / 2; i++)
	{
		if(d[i] != d[e])
		{
			sum += min(b[i], b[e]);
			if(b[i] >= b[e])
			{
				if(i + 1 == e - 1)
				{
					sum += b[i] - b[e];
					break;
				}
				b[i + 1] += b[i] - b[e];
				e--;
			}
			else
			{
				b[e] -= b[i];
			}
		}
		else
		{
			if(b[i] >= b[e])
			{
				b[i + 1] += b[i] - b[e];
				e--;
			}
			else
			{
				b[e] -= b[i];
			}
		}
	}
	cout << sum;
	return 0;
}
