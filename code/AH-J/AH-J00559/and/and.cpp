#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn;
int main()
{
	freopen("and.in","r",stdin)
	freopen("and.out","w",stdout)
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	long long p1 = 0,p2 = 0;
	for (int i = 0;i < n;i++)
	{
		p1 = max(p1,a[i]);
	}
	for (int i = 0;i < n;i++)
	{
		long long p3 = p1 || p2;
		maxn = max(maxn,p3);
	}
	cout << maxn;
	return 0;
}

