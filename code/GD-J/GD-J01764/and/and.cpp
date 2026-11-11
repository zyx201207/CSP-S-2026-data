#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200050],c[200050];
long long sumn(long long o,long long num)
{
	long long sum = -1;
	if (o == 1)
	{
		for (int i = num + 1;i <= m;i++)
		{
			sum = max(sum,sumn(o--,(num & i)));
		}
		return sum;
	}
	else if (o != m)
	{
		for (int i = num + 1;i <= n;i++)
		{
			sum = max(sum,sumn(o--,(num & i)));
		}
		return sum;
	}
	else
	{
		for (int i = 1;i <= n;i++)
		{
			sum = max(sum,sumn(o--,i));
		}
		return sum;
	}
}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int p = sumn(m,0);
	cout << p;
	return 0;
}
