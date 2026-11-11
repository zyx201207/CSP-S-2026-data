#include <bits/stdc++.h>
using namespace std;

long long n, maxn = 0, cnt, cnt1;
long long a[10000000050];
char c[100000050];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    if (n == 1)
    {
		cout << "0";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> c[i];
		maxn = max(a[i], maxn);
        cnt1 += a[i];
	}
	if (n == 2)
	{
		if (c[0] == c[1])
		{
			cout << 0;
		}
		else
		{
			if (a[0] > a[1])
			{
				cout << a[1];
			}
			else
			{
				cout << a[0];
			}
		}
	}
	int j = 0;
	for (int i = n - 1; i >= 0; i++)
    {
        if (c[i] == c[j])
        {
            cnt += abs(a[i] - a[j]);
        }
        cnt1 -= cnt;
    }
    return 0;
}
