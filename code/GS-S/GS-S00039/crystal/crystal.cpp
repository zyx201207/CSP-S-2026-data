#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],h[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	long long maxn = -10000000;
	for (long long i = 2;i<=n;i++)
	{
		long long cnt = 0;
		for (long long j=1;j<i;j++)
		{
			if (cnt + a[i] - a[j] < m)
			{
				cnt += a[i] - a[j];
				continue;
			}
			if (cnt + a[i] - a[j] == m)
			{
				maxn = max(maxn,i);
			}
			if (cnt + a[i] - a[j] > m)
			{
				break;
			}	
		}
	
	}
	cout << maxn;
	return 0;
}
