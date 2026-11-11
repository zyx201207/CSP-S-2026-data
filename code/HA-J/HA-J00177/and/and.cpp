#include <bits/stdc++.h>
using namespace std;
int n,m;
long long f[2001][2001],a[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
			for (int k = 1;k <= j;k++) 
				f[i][j] = max(f[i-1][j],f[i][j]&a[i]);
	cout << f[m][n];
	return 0;
}
