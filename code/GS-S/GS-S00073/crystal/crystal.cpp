#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],k ;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i < n;i++)
	{
		b[i] = (a[i+1] - a[i])*i;
	}
	for (int i = 1;i <= n;i++)
	{
		k+=b[i];
		if (k > m)
		{
			cout << i;
			return 0;
		} 
		
	}
	return 0;
}
