#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10005],maxn=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int b;
		b=b+a[i]+a[i+1];
		maxn=max(b,a[i]);
	}
	cout << maxn;
	return 0;
}
