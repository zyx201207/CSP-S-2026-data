#include <iostream>
using namespace std;
unsigned long long a[200005];
unsigned long long n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int maxn = 0;
	int maxn2 = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(maxn < a[i])
		{
			maxn = a[i];
		}
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = i+1; j <= n; j++)
		{
			int np = a[i] & a[j];
			if(maxn2 < np)
			{
				maxn2 = np;
			}
		}
	}
	int maxn3 = a[1];
	for(int i = 1; i <= n; i++)
	{
		maxn3 = maxn3 & a[i];
	}
	if(m == 1)
	{
		cout << maxn;
	}
	else if(m == 2)
	{
		cout << maxn2;
	}
	else if(m == n)
	{
		cout << maxn3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
