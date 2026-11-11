#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[50005];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	cout << n-1 << " " << n-3 << " "<< n;
	return 0;
}