#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[n];

int main()
{
	freopen("card.in", "r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	while(a[1] != 0)
	{
		for (int i = n - 1; i >= 0; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[j] == a[i])
				{
					
				}
			}
		}
	}
	return 0;
}
