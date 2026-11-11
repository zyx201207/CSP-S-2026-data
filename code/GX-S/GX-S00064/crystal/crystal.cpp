#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005],sum;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		long long num = 1,cnt = 0;
		for(int j = i - 1; j >= 1; j--)
		{
			cnt += a[i] - a[j];
			if(cnt > m)
			{
				break;
			}
			num++;
		}
		sum = max(sum,num);
	}
	cout << sum;
	return 0;
}
