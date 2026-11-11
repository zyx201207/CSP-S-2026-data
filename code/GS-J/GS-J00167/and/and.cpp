#include <bits/stdc++.h>
using namespace std;

int a[200005];
int n,m;

int main ()
{
	freopen("and.in", "r",stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0 ; i < n; i++)
		cin >> a[i];
	
	sort(a[0] , a[n+1]);
	
	int s = 1,sum = 0;
	for (int i = n; i >= 0; i--)
	{
		if (sum <= m)
			s = s & a[i];
		sum++;
	}
	
	cout << s;
	return 0;
}
