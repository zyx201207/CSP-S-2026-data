#include<bits/stdc++.h>
using namespace std; 
long long a[100005],n;
long long bl(long long x,long long mk,long long max)
{
	for (int i = x + 1;i <= n;i++)
	{
		if ((a[x] & a[i]) >= max)
		{
			max = (a[x] & a[i]);
		}
	}
	if (mk == 0)
	{
		cout << max;
		return 0;
	}
	else
	{
		bl(x + 1,--mk,max);
	}
 } 
int main()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	long long m;
	cin >> n >>m ;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	long long mk = m;
	long long max = -1;
	bl(1,mk,max);
	return 0;
}
