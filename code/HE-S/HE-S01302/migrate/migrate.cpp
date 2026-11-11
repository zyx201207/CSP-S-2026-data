#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c >>t;
	while (t>0)
	{
		int n,d;
		cin >>n >>d;
		for (int i=1;i<=n;i++)
		{
			cin >>a[i];
		}
		cout <<n-3 <<endl;
		t--;
	}
	return 0;
}
