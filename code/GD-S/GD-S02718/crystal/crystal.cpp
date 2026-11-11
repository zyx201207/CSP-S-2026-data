#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	long long a[500010] = {};
	
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long ans = 1;
	for(long long i = 1;i <= n;i++)
	{
		long long cnt = 0;
		for(long long j = i-1;j >= 1;j--)
		{
			cnt += a[i] - a[j];
			if(cnt <= m && i-j+1 >= ans)
			{
				ans = i-j+1;
			}
		}
	}
	cout << ans;
	return 0;
}
