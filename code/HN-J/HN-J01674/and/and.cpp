#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],b[200010],max;
int main()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		b[i] = a[i] % 2;
	}	
	return 0;
}
