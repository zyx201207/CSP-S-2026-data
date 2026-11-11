#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005],maxn = -1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxn = max(maxn,a[i]);
	}
	if(m == 1)
	{
		cout << maxn;
	}
	else if(m == n)
	{
		int sum;
		sum = a[n] & a[n-1];
		for (int i = n-2; i>=1; i--)
		{
			sum &= a[i];
		}
		cout << sum;
	}
	else if(m == 2)
	{
		maxn = -1; 
		for(int i = 1; i <= n-1; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				maxn = max(maxn,a[i] & a[j]);
			}
		} 
		cout << maxn;
	}
	else{
		cout << 1;
	}
	return 0;
}
