#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s;
	long long ans = 0;
	long long len = 0;
	cin >> n;
	for(long long i = 1;i <= n;i ++)
	{
		long long x;
		char y;
		cin >> x ;
		cin >> y;
		int cnt =(y - 'a') + 1;
		for(long long j = 1;j <= x;j ++)
		{
			len ++;
			s[len] = cnt;
		}
	}
	if(len % 2 == 0)
	{
		for(long long i = 1;i <= len / 2;i ++)
		{
			for(long long j = len;j >= len / 2 + 1;j --)
			{
				if(s[i] != s[j])	ans ++;
			}
		}
	}
	else if(len % 2 != 0)
	{
		for(long long i = 1;i <= len / 2;i ++)
		{
			for(long long j = len ;j >= len / 2 + 2;j --)
			{
				if(s[i] != s[j])	ans ++;
			}
		}
	}
	cout << ans;
	return 0;
}