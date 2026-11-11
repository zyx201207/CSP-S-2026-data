#include<bits/stdc++.h>

using namespace std;
long long m,a[500005];
int n;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort (a,a + n);
	a[0] = a[1] - a[0];
	for (int i = 1;i < n - 1;i++)
	{
		a[i] = a[i - 1] + (a[i + 1] - a[i]) * (i + 1);
		if(a[i] > m)
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << n;
	return 0;	
}
