#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[10005][10005];
bool cmp (int a, int b)
{
	if (a<b) return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}	
	sort (a+1, a+1+n, cmp);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			b[i][j] = a[j]-a[i];
		}
	}
	int sum=m,num=1,minn = -1;
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (sum == 0)
				if (sum > minn) minn = sum;
			if (b[i][j] >=0 && b[i][j] <= sum)
			{
				sum-=b[i][j];
				num++;
			}
		}
		sum = m;
	}
	cout << sum-sum/2;
	return 0;
}
