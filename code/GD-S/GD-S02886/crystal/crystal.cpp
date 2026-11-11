#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long a[N],b[N],n,m,cnt = 0;


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i]; 
	}
	long long mul = a[2] - a[1];
	bool flag = true;
	for(long long i = 3;i <= n;i++)
		if((a[i] - a[i - 1]) != mul)
			flag = false;
	if(flag == true)
	{
		int cn = 0;
		int sum = 0;
		for(int i = 0;i <= n;i += 2)
		{
			cn += mul;
			sum += cn;
			if(sum >= m)
			{
				cout << i + 1;
				return 0;
			}
			sum += cn;
			if(sum >= m)
			{
				cout << i + 2;
				return 0;
			}
		}
		cout << n;
	}
	else
	{
		sort(a + 1,a + n + 1);
		for(long long i = 2;i <= n;i++)
		{
			b[i] = a[i] - a[i - 1];
		}
		long long maxn = 0;
		for(long long i = 2;i <= n;i++)
		{
			cnt = 0;
			long long k = 0;
			for(int j = i;j >= 1;j--)
			{
				if(m - cnt <= b[j])
				{
					k = i - j + 1;
					maxn = max(maxn,k);
					break;
				}
				else cnt += b[j];
				if(cnt <= m && j == 1)
				{
					maxn = max(maxn,i);
				}
			}
		}
		if(a[n] - a[1] <= m) cout << n;
		else cout << maxn;
	}
	return 0;
}
