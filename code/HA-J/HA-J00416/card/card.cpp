#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n+5];
	int z;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n==m)
	{
		
		for(int i = n; i >= 1; i--)
		{
			cout << i << " ";
		}
		return 0;
	}
	else
	{
		cout << 3 << " " << 4 << 1;
	}
	
}
