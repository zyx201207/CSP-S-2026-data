#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long sum = -1;
	int x=n, y=n-m+1,minc=10000000;
	while(y>0 && x>0){
		long long num = a[x];
		// if(a[x]-a[y]>minc)
		// 	continue;
		// else
		// 	minc=a[x] - a[y];
		for (int i = x-1; i >= y; i--)
		{
			num = num & a[i];
		}
		sum = max(num, sum);
		y--;
		x--;
	}
	cout << sum;
	return 0;
}
