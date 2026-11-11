#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,j;
ll m,a[500005],use,d[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
		d[i] = a[i]-a[i-1];
	for(j = 1;j <= n && use + d[j]*(j-1) <= m;j++)
	{
		use += d[j]*(j-1);
	}
	cout << j-1;
	return 0;
}