#include <bits/stdc++.h>
using namespace std;

long long n, j = 1, num;
long long a[200010];
char c[200010];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(long long i = 1; i <= n; i ++, j ++)
	{
		cin >> a[j] >> c[j];
		if(c[j] == c[j - 1])
		{
			a[j - 1] += a[j];
			j --;
		}
	}
	j --;
	if(j <= 1)
	{
		cout << 0;
		return 0;
	}
	for(long long i = 1, k = j; i <= k;)
	{
		if(i == k)
		{
			break;
		}
		else if(c[i] != c[k])
		{
			if(a[i] == a[k])
			{
				num += a[i];
				i ++;
				k --;
			}
			else if(a[i] > a[k])
			{
				num += a[k];
				a[i] -= a[k];
				k --;
			}
			else if(a[i] < a[k])
			{
				num += a[i];
				a[k] -= a[i];
				i ++;
			}
		}
		else if(c[i] == c[k])
		{
			if(a[i] == a[k])
			{
				i ++;
				k --;
			}
			else if(a[i] > a[k])
			{
				a[i] -= a[k];
				k --;
			}
			else if(a[i] < a[k])
			{
				a[k] -= a[i];
				i ++;
			}
		}
	}
	cout << num;
	return 0;
}
