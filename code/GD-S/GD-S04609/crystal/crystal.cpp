#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],b[1000010],c[1000010],num;
long long m,sum;
void tx()
{
	for(int i=num+1;i<=n;i++)
	{
		if (a[i] != a[1])break;
		num++;
	}
	sum += num;
	for(int i=1;i<=num;i++)
		a[i]++;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	num = 1;
	for(int i=0;i<m;i+=num)
		tx();
	if (sum > m)
	{
		if (sum - m > num - (sum - m))
			num = sum - m;
		else
		{
			num -= sum - m;
			a[1]--;
		}
	}
	for(int i=num+(sum-m)+1;i<=n;i++)
	{
		if (a[i] != a[1])break;
		num++;
	}
	cout << num;
	return 0;
}
