#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n , m , a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(m == 1)
	{
		sort(a + 1 , a + n + 1 , greater<int>());
		cout << a[1];
		return 0;
	}
	if(m == 2)
	{
		int best = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(i != j)
					best = max(best , a[i] & a[j]);
		cout << best;
		return 0;
	}
	if(m == n)
	{
		int k = a[1];
		for(int i = 2; i <= n; i++) k &= a[i];
		cout << k;
		return 0;
	}
	if(m == n - 1)
	{
		int best = 0;
		for(int i = 1; i <= 2; i++)
		{
			int total = a[i];
			for(int j = i + 1; j <= n; j++)
			{
				total &= a[i];
			}
			best = max(best , total);
		}
		cout << best;
		return 0;
	}
	return 0;
}
