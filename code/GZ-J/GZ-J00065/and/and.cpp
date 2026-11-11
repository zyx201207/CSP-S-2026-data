//GZ-J00065遵义第四中学李子煜
#include <bits/stdc++.h>
using namespace std;
const long long M = 2^30;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int b = M;
	int maxn = 0;
	for (int i = 1;i <= n-m+1;i++)
	{
		for (int j = 0;j <= m-1;i++)
		{
			b = b & a[i+j];
		}
		if (b > maxn)
		{
			maxn = b;
		}
	}
	cout << maxn;
	return 0;
}
