#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
long long a[M];
int n;
long long m , cnt , mm , ans , d;
void func(long long x , int id)
{
	mm = m , cnt = 0;
	for(int i = id ; i >= 1 ; i--)
		if(mm - (x - a[i]) >= 0)
		{
			mm -= x - a[i];
			cnt++;		
		}
	ans = max(ans , cnt);
}
bool cmp(long long xx , long long yy)
{
	return xx < yy;
}
void solve1()
{
	for(long long i = 1 ; i <= n ; i++)
		if(i * (i - 1) / 2 == m)
		{
			cout << i;
			return;
		}
		else if(i * (i - 1) / 2 > m)
		{
			cout << i - 1;
			return;
		}
}
void solve2()
{
	if(m % d != 0)
		m -= m % d;
	for(long long i = 1 ; i <= n ; i++)
		if(i * (i + 1) * d == 2 * m)
		{
			cout << i + 1;
			return;
		}
}
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	sort(a + 1 , a + n + 1 , cmp);
	int flag1 = true;
	for(int i = 1 ; i <= n ; i++)
		if(a[i] != i)
			flag1 = false;
	if(flag1)
	{
		solve1();
		return 0;
	}
	d = a[2] - a[1];
	bool flag2 = true;
	for(int i = 2 ; i <= n ; i++)
		if(a[i] - a[i - 1] != d)
			flag2 = false;
	if(flag2)
	{
		solve2();
		return 0;
	}
	int id = 1;
	for(long long i = a[1] ; i <= a[n] ; i++)
	{
		while(i >= a[id + 1])
			id++;
		func(i , id);
	}
	cout << ans;
	return 0;
}
