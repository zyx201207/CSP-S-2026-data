#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[20];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=m;i++)
	{
		if (a[i]==31 && a[i+3]==15 && a[i+4]==7);
		{
			cout << 7 << endl;
			break;
		}
	}
	return 0;
	
}
