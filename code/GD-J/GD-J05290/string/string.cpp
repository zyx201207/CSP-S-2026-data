#include<bits/stdc++.h>
using namespace std;
char a[1000000005];
long long n, x, ru=1, zs, nu; 
char y;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i=1 ; i <= n; i++)
	{
		cin >> x >> y;
		zs+=x;		
		for(int i=1; i <= x; i++)
		{
			a[ru]=y;
			ru++;
		}
	}
	long long q=zs/2;

	for(int i=1; i <= q; i++)
	{
		if(a[i] != a[zs+1-i]) nu++;
	}
	cout << nu;
	return 0;
}
