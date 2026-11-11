#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t;
	cin >> n >> m;
	int a[n+1];
	for(int i = 1;i <= n;i++)
	{
		cin >> t;
		a[i] = t;
	}
	cout << n << m << a[n];
	return 0;
}
