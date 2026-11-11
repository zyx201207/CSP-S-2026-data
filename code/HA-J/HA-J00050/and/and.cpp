#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[105];
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	int maxl=0;
	for (int i=1;i<=n;i++)
	{
		int l=a[i];
		for (int j=2;j<=m;j++)
		{
			l = l & a[i+j];
		}
		if (l > maxl)
			maxl = l;
	}
	cout << maxl <<'\n';
	return 0;
}
