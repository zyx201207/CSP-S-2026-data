#include <bits/stdc++.h>
using namespace std;

long long n,a[200005],m,cnt;
void f(long long p,long long num,long long sum)
{
	if(sum == m)
	{
		cnt = max(cnt,num);
		return;
	}
	if(p > n)
	{
		if(sum == m)
		{
			cnt = max(cnt,num);
		}
		return;
	}
	f(p + 1 , num & a[p] , sum + 1);
	f(p + 1 , num , sum);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		f(1,a[i],0);
	}
	cout << cnt;
	return 0;
}
