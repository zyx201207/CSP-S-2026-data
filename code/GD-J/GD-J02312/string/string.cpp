#include<bits/stdc++.h>
using namespace std;
char x[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long a;
	char b;
	long long cnt = 0;
	long long op;
	long long xx = 1;
	for(long long i = 1;i <= n;i ++)
	{
		cin >> a >> b;
		cnt += a;
		for(long long j = 1;j <= a;j ++)
		{
			x[xx] = b;
			xx ++;
		}
	}
	if(cnt % 2 == 1)
	{
		op = cnt / 2 + 1;
	}
	else
	{
		op = cnt / 2;
	}
	long long ci = 0;
	for(long long i = xx-1;i >= op;i --)
	{
		if(x[i] != x[xx - i])
		{
			ci ++;
		}
	}
	cout << ci;
	return 0;
} 

